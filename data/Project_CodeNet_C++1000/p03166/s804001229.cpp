#include<bits/stdc++.h>
using namespace std;
int dp[100005]={0};
int in[100005]={0};
int vis[100005]={1};
void dfs(int u,vector<int> g[])
{
  vis[u]=1;
  for(auto v : g[u])
  {
    dp[v]=max(dp[v],1+dp[u]);
    --in[v];
    if(in[v]==0)
      dfs(v,g);
  }
}
int main()
{
  int n,m;
  cin>>n>>m;
  int x,y;
  vector<int> g[n+1];
  for(int i=1;i<=m;i++)
  {
    cin>>x>>y;
    g[x].push_back(y);
    ++in[y];
  }
  for(int i=1;i<=n;i++)
  {
    if(vis[i]==0&&in[i]==0)
      dfs(i,g);
  }
  int ans=0;
  for(int i=1;i<=n;i++)
    ans=max(ans,dp[i]);
  cout<<ans<<endl;
}