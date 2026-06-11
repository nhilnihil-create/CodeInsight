#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, sum=0;
    cin>>n;
    int arr[n];

    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);

    for(i=0; i<n-1; i++){
        sum = sum + arr[i];
    }
    cout<<sum+(arr[n-1]/2);
}
