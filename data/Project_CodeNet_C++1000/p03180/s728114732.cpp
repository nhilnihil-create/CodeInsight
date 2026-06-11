#include <iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll inf=(1LL<<60);
ll dp[(1<<16)];
ll sum[(1<<16)];
ll  calculate(vector<vector<int>>& score,int mask)
{
    ll ans=0;
    for(int i=0;i<17;i++)
    {
        for(int j=i+1;j<17;j++)
        {
            if(((mask &(1<<i))!=0) &&((mask & (1<<j))!=0))
            {
                ans+=score[i][j];
            }
        }
    }
    return ans;
}
void prepareSum(vector<vector<int>>& score ,int n)
{   
    for(int subset=1;subset<(1<<n);subset++)
   {
    dp[subset]=inf;
    }
    
    for(int subset=1;subset<(1<<n);subset++)
   {
    sum[subset]=calculate(score,subset);
   }
}
ll solve(vector<vector<int>>& score,int mask)
{  ll ans=0;
    if(mask==0)
    {
        return 0;
    }
    if(dp[mask]!=inf)
    {
        return dp[mask];
    }
    for(ll subset=mask;subset!=0;subset=(subset-1)&mask)
    {
        ans=max(ans,sum[subset]+solve(score,mask^subset));
    }
    return dp[mask]=ans;
}
int main() {
    int n;
    cin>>n;
    vector<vector<int>> score(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>score[i][j];
        }
    }
    prepareSum(score,n);
    cout<<solve(score,(1<<n)-1);
}
