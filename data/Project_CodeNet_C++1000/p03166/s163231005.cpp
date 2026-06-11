#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define s(x, n) memset(x, n, sizeof(x));
#define pb(x) push_back(x)
#define NIL -1

const int MAXN = 1e5 + 10;
vector<int> adj[MAXN];
bool vis[MAXN];
int dist[MAXN];

int dfs(int n)
{
    vis[n] = true;
    //  cout << "n= " << n << "\n";
    if (adj[n].size() == 0)
    {

        dist[n] = 0;
        return dist[0];
    }
    int mx = 0;
    for (int i = 0; i < adj[n].size(); i++)
    {
        if (vis[adj[n][i]] == false)
        {
            //  cout << " child " << adj[n][i] << "\n";
            mx = max(dfs(adj[n][i]), mx);
        }
        else
        {
            mx = max(mx, dist[adj[n][i]]);
        }
    }
    dist[n] = 1 + mx;
    //  cout << "dist " << n << " = " << dist[n] << "\n";
    return dist[n];
}
void ans(int n)
{
    for (int i = 1; i <= n; i++)
    {
        vector<int>::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            dist[*it]++;
        }
    }
    queue<int> q;
    int a = 0;
    for (int i = 1; i <= n; i++)
        if (dist[i] == 0)
            q.push(i);
    s(dist, 0);
    //cout << q.size() << "\n";
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        //  cout << "p= " << p << "\n";
        a = max(a, dfs(p));
    }
    cout << a << "\n";
}

void solve()
{
    s(vis, false);
    s(dist, 0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    ans(n);
}
int main()
{
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifndef WIN32
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    int t;
    t = 1;
    /// cin >> t;
    for (int I = 1; I <= t; I++)
    {
        solve();
    }
    return 0;
}