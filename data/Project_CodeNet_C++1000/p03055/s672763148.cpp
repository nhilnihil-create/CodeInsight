#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef pair<int, int> pii;

const int MAX_N = 200 * 1000 + 5;
int n;
vector<int> adj[MAX_N];

void read_input()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

pii dfs(int v, int par = -1, int h = 0)
{
    pii res = {h, v};
    for (int u : adj[v])
        if (u != par)
            res = max(res, dfs(u, v, h + 1));
    return res;
}

void solve()
{
    int x = dfs(dfs(0).S).F;
    if (x % 3 == 1)
        cout << "Second";
    else
        cout << "First";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    read_input();
    solve();
}