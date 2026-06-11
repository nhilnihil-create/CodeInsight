#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,n;
    int arr[1000];

    cin>>n;
    for(i=0 ; i<n ; i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);
    //x = abs(arr[0])
    cout<<abs(arr[0] - arr[n-1]);
}