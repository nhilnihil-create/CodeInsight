#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define li long
#define pb push_back
#define mem(arr,x) memset(arr,x,sizeof(arr))
int dis[100010];
vector<int>adj[100010];

void dfs(int node)
{
  for(auto child:adj[node])
  {
    if(dis[child]==0)
    dfs(child);
    dis[node]=max(dis[node],1+dis[child]);
  }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i,u,v;
    cin>>n>>m;
    vector<int>indeg(n+1,0);
    for(i=0;i<m;i++)
    {
      cin>>u>>v;
      adj[u].pb(v);
      indeg[v]++;
    }
    vector<int>vertices;
    for(i=1;i<=n;i++)
    {
      if(indeg[i]==0)
      vertices.pb(i);
    }
    mem(dis,0);
    for(auto vertex:vertices)
    {
      dis[vertex]=0;
      dfs(vertex);
    }
    int ans=0;
    for(i=1;i<=n;i++)
    ans=max(ans,dis[i]);
    cout<<ans;
    return 0;
}