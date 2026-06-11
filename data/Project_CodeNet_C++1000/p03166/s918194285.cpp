#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(i, a) for (auto &i: (a))
#define sz(x) (int)(x).size()
#define all(v) (v).begin(), (v).end()
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    clock_t beg = clock();
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif 
    int t = 1; 
    // cin >> t;    
    int tt = t;
    while (t--) {
        // cout << "Case #" << tt - t << ": "; 
        solve();
    }
    cerr << "\nExecution time: " << (clock() - beg) / 1000 << '\n';
    return 0;
}
const int N = 1e5 + 5;
vector<int> adj[N]; // adj[0], adj[1], ..., adj[N - 1]
int dp[N];
int longest_path(int v) {
    if (dp[v] != -1) {
        return dp[v];
    }
    int ans = 0;
    for (auto i : adj[v]) {
        ans = max(ans, longest_path(i) + 1);
    }   
    return dp[v] = ans;
}

void solve() {  
    int n, m;
    cin >> n >> m;
    fill(dp, dp + N, -1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }   
    int mx = 0; 
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, longest_path(i));
    }
    cout << mx;
}