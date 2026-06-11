#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll minm;
ll dp[100001];
int fn(ll a[],ll n)
{
    if(n==0)
    {
        dp[0] = min(minm,dp[0]);
        return dp[0];
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    else if(n>=2)
    {
       ll x = abs(a[n]-a[n-1]);
       ll y = abs(a[n]-a[n-2]);
       return dp[n] = min(x+fn(a,n-1),y+fn(a,n-2));
    }
    else
    {
        ll x = abs(a[n]-a[n-1]);
       return dp[n] = x + fn(a,n-1); 
    }
    return 0;
}
int main()
{
    ll i,n;
    cin>>n;
    ll a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[0] = INT_MAX;
    fn(a,n-1);
    cout<<dp[n-1]<<"\n";
    return 0;
}