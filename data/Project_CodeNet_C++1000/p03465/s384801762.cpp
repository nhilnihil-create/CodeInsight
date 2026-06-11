#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    bitset<2000009> arr;
    long long n,i,sum=0;
    cin>>n;
    long long a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    arr[0]=1;
    for(i=0;i<n;i++)
    {
        arr=arr|(arr<<a[i]);
    }
    for(i=sum/2;i>=0;i--)
    {
        if(arr[i]==1)
        {
            cout<<sum-i;
            break;
        }
    }
    return 0;
}