#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

ll N;
vector<ll> g[100100];

// 頂点 cur
// 0: 白 
// 1: 黒
ll dp[100100][2];

void dfs(int cur, int par = -1) {
    dp[cur][0] = 1;
    dp[cur][1] = 1;
    for (int i = 0; i < g[cur].size(); i++) {
        ll to = g[cur][i];
        if (to == par) continue;

        dfs(to, cur);

        // cout << "to: " << to << " <- cur: " << cur << endl;
        // 戻りがけになんかする
        dp[cur][0] *= (dp[to][0] + dp[to][1]); 
        dp[cur][0] %= MOD; 

        dp[cur][1] *= dp[to][0];
        dp[cur][1] %= MOD; 
    }
}
int main() {
    cin >> N;
    rep(i, N - 1) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0);
    // cout << dp[0][0] << " " << dp[0][1] << endl;

    ll ans = dp[0][0];
    ans += dp[0][1];
    ans %= MOD;
    cout << ans << endl;
}