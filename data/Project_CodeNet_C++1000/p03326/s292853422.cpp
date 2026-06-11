#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

ll dp[1001][1001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];

    ll ans = -linf;
    for (int bits = 0; bits < (1 << 3); bits++) {
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) dp[0][i] = -linf;
        for (int i = 0; i < n; i++) {
                ll X = x[i]; if (bits & (1 << 0)) X *= -1;
                ll Y = y[i]; if (bits & (1 << 1)) Y *= -1;
                ll Z = z[i]; if (bits & (1 << 2)) Z *= -1;
            for (int j = 1; j <= m; j++) {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - 1] + X + Y + Z);
            }
        }
        ans = max(ans, dp[n][m]);
    }
    cout << ans << endl;
    return 0;
}
