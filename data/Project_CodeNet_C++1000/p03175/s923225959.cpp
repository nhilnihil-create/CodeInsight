#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define int long long int
#define double long double
#define inf (int)(1e15)
#define all(x) (x).begin(), (x).end()
#define pair pair<int, int>
typedef vector<int> vi;   // Vector of long long
typedef vector<vi> vvi;   // Vector of vi
typedef vector<pair> vii; // Vector of pairs
typedef vector<vii> vvii; // Vector of Vector of pairs
typedef vector<bool> vb;  // Vector of bool
#define pq priority_queue // Max heap (To convert to min heap, use negative sign before every value)
#define ff first          // For pairs
#define ss second
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, -1, 0, 1};
const int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}, dy8[] = {1, -1, 1, 0, -1, 1, -0, -1};
#define testcases(t) \
    int(t);          \
    cin >> (t);      \
    while ((t)--)
vvi adj;
int n, m, u, v;
int dp[(int)(1e5 + 4)][2];
void dfs(int v, int p)
{
    dp[v][0] = 1, dp[v][1] = 1;
    for (auto it : adj[v])
    {
        if (it == p)
            continue;
        dfs(it, v);
        dp[v][1] *= dp[it][0];
        dp[v][1] %= mod;
        dp[v][0] *= (dp[it][0] + dp[it][1]);
        dp[v][0] %= mod;
    }
    return;
}
signed main()
{
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 1);
    cout << ((dp[1][0] + dp[1][1]) % mod) << endl;
    return 0;
}