#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    int sum=0;
    for(int i=0;i<n-1;i++)sum+=arr[i];
    if(sum>arr[n-1])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
