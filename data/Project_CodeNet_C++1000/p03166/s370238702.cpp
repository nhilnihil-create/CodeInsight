#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
int dp[100005];
int fun(int idx)
{
    int &ret=dp[idx];
    if(~ret) return ret;
    ret=0;
    for(int i=0;i<adj[idx].size();i++)
    {
        ret=max(ret,1+fun(adj[idx][i]));
    }
    return ret;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int ans=1;
    for(int i=1;i<=n;i++)
        ans=max(ans,fun(i));
    cout<<ans<<endl;
}
