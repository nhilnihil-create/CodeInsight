#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pdd = pair<double, double>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<vector<ll>> dp(N + 1, vector<ll>(K + 1));
    for (int i = 0; i <= K; ++i)
        dp[0][i] = 1;

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j <= K; ++j) {
            if (j <= a)
                dp[i + 1][j] += dp[i][j];
            else
                dp[i + 1][j] += dp[i][j] - dp[i][j - a - 1];
            if (j > 0)
                dp[i + 1][j] += dp[i + 1][j - 1];
            dp[i + 1][j] %= MOD;
        }
    }

    ll ans = dp[N][K];
    if (K > 0)
        ans -= dp[N][K - 1];
    ans %= MOD;
    if (ans < 0)
        ans += MOD;
    cout << ans << endl;

    return 0;
}
