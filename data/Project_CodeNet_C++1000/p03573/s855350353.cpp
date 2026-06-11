#include <bits/stdc++.h>
using namespace std;
map<long,long>mp;
int main()
{
    long i,j,t,a,b,n,c,y,m,prev,sum,ans=1;
    t=1;
    // cin>>t;
    while(t--)
    {
       int arr[3];
       cin>>arr[0]>>arr[1]>>arr[2];
       sort(arr,arr+3);
       if(arr[0]!=arr[1])cout<<arr[0];
       else cout<<arr[2];
    }
}