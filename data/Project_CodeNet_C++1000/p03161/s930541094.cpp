#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll minimum;

ll frog(ll *A,ll n,ll k)
{
    ll ans=0,p=0;
    
    ll t[n+1];
    for(int i=0;i<=n;i++)
    t[i]=INT_MAX;
    
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        t[i]=0;
    
        else if(i>=3&&k>=2)
        {
        for(int j=i-1;j>=max(i-k,p);j--)
            {
            ans=abs(A[i]-A[j])+t[j];
            t[i]=min(ans,t[i]);
            }
        }
        
        else t[i]=abs(A[i]-A[i-1])+t[i-1];
    }
    
    return t[n];
}

int main()
{
    ll n,k,sum=0;
    cin >>n>>k;
    
    minimum=INT_MAX;
    
    ll A[n];
    
    for(int i=1;i<=n;i++)
    cin >>A[i];
    
    if(k==1)
    {
        for(int i=1;i<n;i++)
        sum+=abs(A[i]-A[i+1]);
        
        cout <<sum;
    }
    else cout <<frog(A,n,k);
}