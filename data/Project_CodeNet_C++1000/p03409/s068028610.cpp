#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

int rx[100], ry[100];
int bx[100], by[100];

vector<int> adj[100];
int vis[100];
int match[100];

int dfs(int x)
{
    if (vis[x])
        return 0;

    vis[x] = 1;
    for (int y : adj[x])
    {
        if (match[y] == -1 || dfs(match[y]))
        {
            match[y] = x;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> rx[i] >> ry[i];
    for (int i = 0; i < n; ++i)
        cin >> bx[i] >> by[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (rx[i] < bx[j] && ry[i] < by[j])
                adj[i].push_back(j);
        }
    }
    int sol = 0;
    memset(match, -1, sizeof match);
    for (int i = 0; i < n; ++i)
    {
        memset(vis, 0, sizeof vis);
        if (dfs(i))
            sol++;
    }
    cout << sol;
}
