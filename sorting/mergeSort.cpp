#include <bits/stdc++.h>
using namespace std;

void mergeArr(int* arr, int l, int m, int r){
    
    if(l < r){
        int temp[r - l + 1];

        int i = l;
        int k = m + 1;
        int j = 0;

        while (i <= m && k <= r)
        {
            if (arr[i] < arr[k])
            {
                temp[j] = arr[i];
                j++;
                i++;
            }
            else if (arr[k] < arr[i])
            {
                temp[j] = arr[k];
                j++;
                k++;
            }
            else
            {
                temp[j] = arr[i];
                j++;
                i++;
                temp[j] = arr[k];
                j++;
                k++;
            }
        }

        if (i <= m)
        {
            while (i <= m)
            {
                temp[j] = arr[i];
                j++;
                i++;
            }
        }

        if (k <= r)
        {
            while (k <= r)
            {
                temp[j] = arr[k];
                j++;
                k++;
            }
        }

        int a = 0;

        for (int i = l; i <= r; i++)
        {
            arr[i] = temp[a];
            a++;
        }

    }
}


void msort(int* arr, int l, int r){
    
    if(l < r){

        int mid = (l + r)/2;
        
        msort(arr, l, mid);
        msort(arr, mid + 1, r);
        mergeArr(arr, l, mid, r);

    }

}


int main (){
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    msort(arr, 0, n-1);

    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}
