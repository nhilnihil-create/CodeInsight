#include <bits/stdc++.h>
using namespace std;
int V;
int MAXV = 1000;
vector<vector<int>> g(MAXV);
vector<int> match(MAXV);
vector<bool> used(MAXV);
void add_edge(int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}
bool dfs(int v)
{
    used[v] = true;
    for(int u : g[v])
    {
        int w = match[u];
        if(w < 0 || (!used[w] && dfs(w)))
        {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res = 0;
    match.assign(MAXV, -1);
    for(int v = 0; v < V; v++)
    {
        if(match[v] < 0)
        {
            used.assign(MAXV, 0);
            if(dfs(v)) res++;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n);
    V = 2*n;
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i] >> d[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i] < c[j] && b[i] < d[j])
            {
                add_edge(i, j+n);
            }
        }
    }
    cout << bipartite_matching() << endl;
}


