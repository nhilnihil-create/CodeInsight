#include<bits/stdc++.h>
using namespace std;
int n,k;
long long dp[100009];
long long arr[100009];
int solve(int idx)
{
    if(idx==n-1) return 0;
    if(dp[idx]!=-1) return dp[idx];
    long long ans=LONG_LONG_MAX;
    for(int i=1;i<=k;i++)
    {
        if(idx+i>=n) break;
        ans=min(ans,solve(idx+i)+abs(arr[idx+i]-arr[idx]));
    }
    return dp[idx]=ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(0)<<endl;
    return 0;
}
