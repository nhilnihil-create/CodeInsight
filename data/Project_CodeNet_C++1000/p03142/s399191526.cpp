#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;

int n, m, l[maxn], r[maxn], BIT[4 * maxn];
int ans[maxn], root;
int dist[maxn], par[maxn], deg[maxn];

vector<int> vt[maxn], inv[maxn];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n + m - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        inv[u].push_back(v);
        vt[v].push_back(u);
        deg[v]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 0)
        {
            root = i;
        }
    }
    queue<int> q;
    vector<int> order(0);
    q.push(root);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for(auto v: inv[u])
        {
            deg[v]--;
            if(deg[v] == 0) q.push(v);
        }
    }
    for(auto i: order)
    {
        if(i == root) continue;
        for(auto j: vt[i])
        {
            if(dist[i] < dist[j] + 1)
            {
                dist[i] = dist[j] + 1;
                par[i] = j;
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << par[i] << '\n';
}