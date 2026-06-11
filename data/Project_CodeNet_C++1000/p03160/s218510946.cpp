#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[100009],ans;
long long arr[100009];
int solve(int idx)
{
    if(idx==n-1) return 0;
    if(dp[idx]!=-1) return dp[idx];
    ans=solve(idx+1)+(abs(arr[idx+1]-arr[idx]));
    if(idx+2<n)
       {
           ans=min(ans,solve(idx+2)+ abs(arr[idx+2]-arr[idx]));
       }
    return dp[idx]=ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<solve(0)<<endl;
    return 0;
}
