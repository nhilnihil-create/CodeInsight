#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long arr[n+1];
    arr[0]=2;arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n];

    return 0;
   }