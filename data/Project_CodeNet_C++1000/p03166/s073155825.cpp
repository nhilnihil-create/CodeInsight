// https://atcoder.jp/contests/dp/tasks/dp_g

#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int a[100005];
bool vis[100005];

void DFS(vector<int> adj[] , int s)
{
    vis[s] = 1;
    for(int i=0 ; i<adj[s].size() ;i++)
    {
        if(!vis[adj[s][i]])
        {
            DFS(adj,adj[s][i]);
        }
        a[s] = max(a[adj[s][i]]+1,a[s]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];
    bool in[n+1]={0};
    for(int i=0 ; i<m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v] = 1;
    }
    for(int i=1 ; i<=n ; i++)
    {
        if(!vis[i])
        {
            DFS(adj,i);
        }
    }
    int ans = 0;
    for(int i=1;  i<=n ; i++)
        ans = max(ans,a[i]);
    cout << ans;
    return 0;
}
