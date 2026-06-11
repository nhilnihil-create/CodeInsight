#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<ll> c(1 << n);
    for (int s = 0; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (((s >> i) & 1) && ((s >> j) & 1)) c[s] += a[i][j];
            }
        }
    }

    vector<ll> dp(1 << n);
    for (int s = 0; s < (1 << n); s++) {
        for (int t = s; t > 0; --t &= s) {
            dp[s] = max(dp[s], dp[s ^ t] + c[t]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
