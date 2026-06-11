#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100009];
bool vis[100009];
int dis[100009];
int dfs(int node)
{
    vis[node]=true;
    int ans=0;
    if(dis[node]!=-1)
     return dis[node];
    for(int x:adj[node])
     ans=max(ans,1+dfs(x));
    return dis[node]=ans;
}
int main(){
    int n,m,u,v;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
      cin>>u>>v;
      adj[u].push_back(v);
    }
    int ans=0;
    memset(dis,-1,sizeof(dis));
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
        {
            ans=max(ans,dfs(i));
        }

    }
    cout<<ans<<endl;
}