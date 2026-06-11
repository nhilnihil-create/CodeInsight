#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; ll k; cin >> n >> k;
    vector<ll> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> cnt(40, vector<int>(2));
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < n; j++) {
            cnt[i][(a[j] >> i) & 1]++;
        }
    }

    vector<vector<ll>> dp(41, vector<ll>(2, -1));
    dp[40][0] = 0;
    for (int i = 39; i >= 0; i--) {
        if ((k >> i) & 1) {
            dp[i][0] = (dp[i + 1][0] << 1) + cnt[i][0];
            dp[i][1] = (dp[i + 1][0] << 1) + cnt[i][1];
        } else {
            dp[i][0] = (dp[i + 1][0] << 1) + cnt[i][1];
        }
        if (dp[i + 1][1] >= 0) {
            dp[i][1] = max(dp[i][1], (dp[i + 1][1] << 1) + max(cnt[i][0], cnt[i][1]));
        }
    }

    cout << max(dp[0][0], dp[0][1]) << endl;
    return 0;
}
