#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[5],k;
    for(int i=0; i < 5; ++i) cin >> arr[i];
    cin>>k;
    sort(arr,arr+5);
    cout << (arr[4]-arr[0]>k?":(":"Yay!");
    return 0;
}
