#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int> adj[100001];
int dp[100001];
int dfs(int node)
{
   if(dp[node]!=-1)
       return dp[node];
   dp[node]=0;
   for(int i=0;i<adj[node].size();++i)
   {
       dp[node]=max(dp[node],1+dfs(adj[node][i]));
   }
   return dp[node];
}
signed main()
{
   SPEED;
   int n,m,ans=0;
   cin>>n>>m;
   memset(dp,-1,sizeof(dp));
   for(int i=0;i<m;++i)
   {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
   }
   for(int i=1;i<=n;++i)
   {
       ans=max(ans,dfs(i));
   }
   cout<<ans;
}