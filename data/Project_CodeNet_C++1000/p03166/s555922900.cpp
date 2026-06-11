#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define INF 1e18
#define EPS 1e-9
#define bitcount __builtin_popcount
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v, d, sizeof(v))
#define rep(i, v) for (int i = 0; i < sz(v); ++i)
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)
#define LSOne(S) (S & (-S))
#define PI acos(-1.0)
#define P(x) cout << #x << " = { " << x << " }\n"
#define tests()  \
    int tttt;    \
    cin >> tttt; \
    while (tttt--)
#define fast_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define file_IO                       \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
typedef long long ll;
int dcmp(long double x, long double y)
{
    return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
const int MAX = 1e5 + 10;
int n, m;
int dp[MAX];
vector<vector<int>> adj;
bool vis[MAX];
void read();
void solve();
void clear();
void dfs(int node);
int main()
{
#ifndef ONLINE_JUDGE
    file_IO;
#else
    fast_IO;
#endif

    solve();
}
void read()
{
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    lp(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }
}
void clear()
{
    clr(dp, -1);
}
void solve()
{
    read();
    //clear();
    lp(i, n)
    {
        if (!vis[i])
            dfs(i);
    }
    cout << *max_element(dp, dp + n) << '\n';
}
void dfs(int node)
{
    vis[node] = 1;
    if (adj[node].size() == 0)
    {
        dp[node] = 0;
        return;
    }
    int mx = 0;
    rep(i, adj[node])
    {
        int child = adj[node][i];
        if (!vis[child])
        {

            dfs(child);
            mx = max(mx, dp[child] + 1);
        }
        else
        {
            mx = max(mx, dp[child] + 1);
        }
    }

    dp[node] += mx;
}