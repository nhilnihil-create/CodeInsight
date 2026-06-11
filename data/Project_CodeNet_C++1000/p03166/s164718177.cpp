#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define all(a) begin(a), end(a)
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": " << a << ENDL
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;

vector<vector<lli>> graph;
vector<lli> dp;

int dfs(int u) {
    if(dp[u] != -1) return dp[u];
    int ret = 0;
    for(auto it : graph[u]) {
        ret = max(ret, dfs(it) + 1);
    }
    dp[u] = ret;
    return ret;
}

int main()
{   _
    lli n, m, u, v; cin >> n >> m;
    graph.resize(n + 1);
    dp.resize(n + 1);
    fill(all(dp), -1);
    fore(i, 0, m) {
        cin >> u >> v;
        graph[u].pb(v);
    }
    int mx = 0;
    fore(i, 1, n + 1) mx = max(mx, dfs(i));
    cout << mx << ENDL;
    return 0;
}
