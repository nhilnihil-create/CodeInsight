#include<bits/stdc++.h>
using namespace std;
const int nax=1e5+5;
vector<int> edges[nax];
int depth[nax];
int in_degree[nax];
vector<bool> visited(nax,false);
void dfs(int u){
    visited[u]=true;
     for(auto v:edges[u]){
        depth[v]=max(depth[v],depth[u]+1);
        in_degree[v]--;
        if(in_degree[v]==0)
            dfs(v);
     }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        in_degree[v]++;
    }
     for(int i=1;i<=n;i++){
        if(!visited[i] && in_degree[i]==0) dfs(i);
     }
     int ans=0;
     for(int i=1;i<=n;i++){
        ans=max(ans,depth[i]);
     }
     cout<<ans;

}
