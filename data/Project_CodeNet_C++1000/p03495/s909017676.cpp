#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,t,a,b,n,c,d,y,temp,m,r,sum,count,k,l,ans;
    t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long arr[n],brr[n];
        memset(brr,0,sizeof(brr));
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            brr[arr[i]]++;
        }
        sort(brr,brr+n);
        reverse(brr,brr+n);
        ans=0;
        for(i=0;i<k;i++)
        ans+=brr[i];
        cout<<n-ans;
        
    }
}