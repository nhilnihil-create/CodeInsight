#include <bits/stdc++.h>
using namespace std;
void dfs(int v,vector<int>& dist,vector<vector<pair<int,int>>>& adj)
{
    for(auto const&e:adj[v])
    {
        int ne=e.first;
        int val=e.second;
        if(dist[ne]==-1)
        {
            if(val==1)
            {
                dist[ne]=1-dist[v];
            }
            else
            {
                dist[ne]=dist[v];
            }
            dfs(ne,dist,adj);
        }
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        adj[a].push_back({b,c%2});
        adj[b].push_back({a,c%2});
    }
    vector<int> dist(n,-1);
    dist[0]=0;
    dfs(0,dist,adj);
    for(auto const&e:dist)
        cout<<e<<" ";
    cout<<"\n";
    return 0;
}