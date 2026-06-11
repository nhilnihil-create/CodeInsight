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
vb visited;
void dfs(int v)
{
    visited[v] = true;
    for (auto it : adj[v])
    {
        if (!visited[it])
            dfs(it);
    }
    return;
}
signed main()
{
    int n, u, v, m, k = 0, z;
    cin >> n >> m;
    adj.resize(n + 1);
    visited.resize(n + 1);
    while (m--)
    {
        cin >> u >> v >> z;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            k++;
        }
    }
    cout << k << endl;
    return 0;
}
