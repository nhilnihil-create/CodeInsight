#include <iostream>
#include <algorithm>

using namespace std;

int n, sum = 0, big = -1, i;

int main(){
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > big){
            big = arr[i];
        }
    }
    sort(arr, arr+n);
    for(i = 0; i < n-1; i++){
        sum += arr[i];
    }

    if(arr[n-1] < sum){
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}