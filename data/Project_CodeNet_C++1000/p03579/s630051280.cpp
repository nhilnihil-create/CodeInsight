#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define pb push_back
#define int long long
const int N = 1e5+5;
int n, m, u, v;
int color[N];
bool visited[N], congthu = 1;
vector<int> adj[N];

void dfs(int u, int c)
{
    for (auto v: adj[u])
    {
        if(color[v] != -1 && color[v] != c) {
            congthu = 0;
        }
        color[v] = c;
    }
    for (auto v: adj[u])
    {
        if(!visited[v]) {
            visited[v] = 1;
            dfs(v, 1 - c);
        }
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(color, -1, sizeof color);
    color[1] = 1;
    visited[1] = 1;
    dfs(1, 0);
    if (!congthu)
        cout << n*(n-1)/2 - m;
    else
    {
        int black = 0, white = 0;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 1) black++;
            else if (color[i] == 0) white++;
        }
        cout << black*white-m;
    }
}
/*
6 5
1 2
2 3
3 4
4 5
5 6
*/
