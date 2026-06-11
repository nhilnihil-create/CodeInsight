#include<bits/stdc++.h>

using namespace std;

int const maxn = 105, maxt = 205, maxv = 105;
double inf = 1000.0 * 1000.0 * 1000.0;
int t[maxn], v[maxn];
int V[2 * maxn * maxt];
int dp[2 * maxn * maxt][2 * maxv];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, N = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) {
        while (t[i]--) {
            V[N++] = v[i];
            V[N++] = v[i];
        }
    }
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < 2 * maxv; ++j) dp[i][j] = -inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= 2 * V[i]; ++j) {
            for (int lst = max(0, j - 1); lst <= j + 1; ++lst) {
                if (j == 2 * V[i] && lst > j) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][lst] + j + lst);
            }
        }
    }
    cout << fixed << setprecision(9) << dp[N - 1][0] / 8.0 << '\n';
    return 0;
}
