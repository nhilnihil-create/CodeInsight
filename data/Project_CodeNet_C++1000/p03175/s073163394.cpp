#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int MAX = 1e+5 + 5;
const ll LINF = 1LL << 50;
const int mod = 1e+9 + 7;
/* global variables */
int N;
vector<vector<int>> G(MAX, vector<int>());
vector<vector<ll>> dp(MAX, vector<ll>(2));
vector<bool> used(MAX);
/* funciton */
void dfs(int x) {
    if (used[x]) return ;
    used[x] = true;
    // dp[x][0] = Node-x, White
    // dp[x][1] = Node-x, Black
    dp[x][0] = 1;
    dp[x][1] = 1;
    for (int y : G[x]) {  // y = x.child
        if (used[y]) continue;
        dfs(y);
        // x-(White) -> x.child-(White or Black)
        dp[x][0] = (dp[x][0] * (dp[y][0] + dp[y][1])) % mod;
        // x-(Black) -> x.child-(White)
        dp[x][1] = (dp[x][1] * dp[y][0]) % mod;
    }
}
/* main */
int main() {
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0);
    ll ans = (dp[0][0] + dp[0][1]) % mod;
    cout << ans << '\n';
}