//
//  main.cpp
//  5_Merge_Sort
//
//  Created by 세광 on 2021/08/05.
//

#include <iostream>

using namespace std;

class MergeSort {
public:
    MergeSort();
    ~MergeSort();
    
    void Partition(int, int);
    void Sort(int, int, int);
    const int GetIndex() const;
    void SetX();
    void Print();
    
private:
    int *arr, *temp;
    int index;
    bool x;
};

int main() {
    MergeSort *sort = new MergeSort;
    sort->Partition(0, sort->GetIndex() - 1);
    sort->Print();
    sort->SetX();
    sort->Partition(0, sort->GetIndex() - 1);
    sort->Print();
    delete sort;
}

MergeSort::MergeSort() : x(false) {
    cin >> index;
    arr = new int[index];
    temp = new int[index];
    for (size_t t = 0; t < index; t++) {
        cin >> arr[t];
    }
}

MergeSort::~MergeSort() {
    delete [] arr;
    delete [] temp;
    arr = NULL;
    temp = NULL;
}

void MergeSort::Partition(int m, int n) {
    if (m < n) {
        int mid = (m + n) / 2;
        Partition(m, mid);
        Partition(mid + 1, n);
        Sort(m, mid, n);
    }
}

void MergeSort::Sort(int m, int mid, int n) {
    int i = m;
    int j = mid + 1;
    int k = m;
    
    while (i <= mid && j <= n) {
        if (x == false) {
            if (arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        } else {
            if (arr[i] >= arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
    }
    
    if (i > mid) {
        for (size_t t = j; t <= n; t++) {
            temp[k] = arr[t];
            k++;
        }
    } else {
        for (size_t t = i; t <= mid; t++) {
            temp[k] = arr[t];
            k++;
        }
    }
    
    for (size_t t = m; t <= n; t++) arr[t] = temp[t];
}

const int MergeSort::GetIndex() const { return index; }

void MergeSort::SetX() {
    if (x == false) x = true;
    else x = false;
}

void MergeSort::Print() {
    for (size_t t = 0; t < index; t++) cout << arr[t] << ' ';
    cout << endl;
}
