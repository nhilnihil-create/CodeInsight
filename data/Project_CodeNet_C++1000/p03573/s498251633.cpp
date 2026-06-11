#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr,arr+3);

    arr[2]==arr[1]?cout<<arr[0]:cout<<arr[2];
    return 0;
}