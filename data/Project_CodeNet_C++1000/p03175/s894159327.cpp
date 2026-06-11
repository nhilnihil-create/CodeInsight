#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ENDL '\n'
#define all(a) begin(a),end(a)
#define sz(a) (int)(a.size())
#define deb(a) cout << #a << ": "  << a << ENDL
#define fore(i, a, b) for(int i(a), ThkMk(b); i < ThkMk; ++i)
#define _ ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long lli;
typedef long double ld;
typedef pair<lli, lli> ii;

const int MAXN = 1e5 + 5;

lli dp[2][MAXN];

lli MOD = 1e9 + 7;

vector<vector<lli>> graph;

lli n;

lli dfs(int u, int pr, int color) {
    lli &ans = dp[color][u];
    if(ans != -1) return ans;
    ans = 1;
    for(auto it : graph[u]) {
        if(it == pr) continue;
        lli cur = dfs(it, u, 0);
        if(color == 0) cur = (cur + dfs(it, u, 1)) % MOD;
        ans = (ans * cur) % MOD;
    }
    return ans;
}

int main()
{   _
    fore(i, 0, 2) fore(j, 0, MAXN) dp[i][j] = -1;
    lli u, v; cin >> n;
    graph.resize(n);
    fore(i, 1, n) {
        cin >> u >> v;
        graph[u - 1].pb(v - 1);
        graph[v - 1].pb(u - 1);
    }
    cout << (dfs(0, -1, 0) + dfs(0, -1, 1)) % MOD << ENDL;
    return 0;
}
