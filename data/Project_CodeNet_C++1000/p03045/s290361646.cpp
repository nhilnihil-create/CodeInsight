#include <bits/stdc++.h>
using namespace std;
void dfs(int v,vector<bool>& visited,vector<vector<int>>& adj)
{
    visited[v]=true;
    for(auto const&e:adj[v])
    {
        if(!visited[e])
        {
            dfs(e,visited,adj);
        }
    }
    return;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans=0;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            ans++;
            dfs(i,visited,adj);
        }
    }
    cout<<ans<<"\n";
    return 0;
}