#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int Nmax = 1e5 + 5;

int n,m,u,v;
int par[Nmax];

vector <int> adj[Nmax];
vector <int> topo;

bool visited[Nmax];
void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v]) dfs(v);
    }
    topo.push_back(u);
}


int main()
{
    //freopen("file.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i < n + m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]) dfs(i);
    }
    reverse(topo.begin(), topo.end());
    for (int i = 0; i < n; i++)
    {
        int u = topo[i];
        for (int v : adj[u])
        {
            par[v] = u;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << par[i] << endl;
    }
    return 0;
}
