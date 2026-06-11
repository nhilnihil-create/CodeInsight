#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define PI 3.14159265359
#define sz(c) (int)c.size()
#define len(c) (int)c.length()
#define hcf(a, b) __gcd(a, b)
#define all(c) c.begin(), c.end()
#define vint vector<int>
#define vll vector<ll>
#define vpint vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define fr(it, a, b) \
    for (int it = (a); it < (b); it++)
#define tr(con, it) \
    for (auto it = con.begin(); it != con.end(); it++)
#define present(con, ele) (con.find(ele) != con.end())
#define cpresent(con, ele) (find(all(con), ele) != con.end())
#define maximum(a, b, c) (a > b ? (a > c ? a : c) : (b > c ? b : c))
#define minimum(a, b, c) (a < b ? (a < c ? a : c) : (b < c ? b : c))
typedef long long ll;
typedef long double lf;
typedef pair<int, int> pi;
typedef unsigned long long lu;
const ll mod = 1e9 + 7;
void dfs(int node, vector<bool> &vis, vector<vint> &adj)
{
    vis[node] = true;
    for (auto u : adj[node])
    {
        if (!vis[u])
            dfs(u, vis, adj);
    }
}
int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vint> adj(n);
    fr(i, 0, m)
    {
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool> vis(n, false);
    fr(i, 0, n)
    {
        if (!vis[i])
        {
            ans++;
            dfs(i, vis, adj);
        }
    }
    cout << ans << "\n";
    return 0;
}