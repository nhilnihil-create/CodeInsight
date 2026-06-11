#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+1;
vector<ll> gr[maxn];
ll dp[maxn];
bool vis[maxn];
ll ans,i,m,n,u,v,j;
void dfs(ll node)
{
    vis[node]=true;
    for (auto i:gr[node])
    {
        if (!vis[i]) dfs(i);
        dp[node]=max(dp[node],1+dp[i]);
    }
}
long long find_l()
{
    memset(vis,false,sizeof(vis));
    for (i=1;i<=n;i++) if (!vis[i]) dfs(i);
    ans=0;
    for (i=1;i<=n;i++) ans=max(ans,dp[i]);
    return ans;
}
int main()
{
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        cin>>u>>v;
        gr[u].push_back(v);
    }
    cout<<find_l()<<endl;
}
