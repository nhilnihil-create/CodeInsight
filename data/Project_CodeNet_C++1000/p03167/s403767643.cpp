#include <bits/stdc++.h>
#define ll long long

using namespace std;
constexpr int ms = 1001;
constexpr ll mod = 1e9+7;

void solve() {
    int h, w;
    cin >> h >> w;

    ll dp[ms][ms];
    memset(dp, -1, sizeof(dp));

    vector<string> vs(h);
    for (int i = 0; i < h; ++i) {
        cin >> vs[i];
    }

    function<ll(int i, int j)> calc_dp = [&] (int i, int j) {
        if (i < 0 || j < 0)
            return 0ll;

        if (i == 0 && j == 0)
            return 1ll;

        if (vs[i][j] == '#')
            return 0ll;

        if (dp[i][j] != -1) 
            return dp[i][j];
        
        dp[i][j] = (calc_dp(i-1, j) + calc_dp(i, j-1)) % mod;
        return dp[i][j];
    };

    cout << calc_dp(h-1, w-1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
