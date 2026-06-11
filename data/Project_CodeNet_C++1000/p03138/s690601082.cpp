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

    int N;
    ll K;
    cin >> N >> K;
    vector<ll> cnt(45);
    for (int i = 0; i < N; ++i) {
        ll A;
        cin >> A;
        for (int j = 0; j < 45; ++j)
            if ((A >> j) & 1)
                cnt[j]++;
    }

    vector<vector<ll>> dp(45, vector<ll>(2, -1));
    dp[44][1] = 0;
    for (int i = 43; i >= 0; --i) {
        if (~dp[i + 1][0]) {
            dp[i][0] = max(dp[i + 1][0] + (cnt[i] << i), dp[i][0]);
            dp[i][0] = max(dp[i + 1][0] + ((N - cnt[i]) << i), dp[i][0]);
        }
        if (~dp[i + 1][1]) {
            if ((K >> i) & 1) {
                dp[i][0] = max(dp[i + 1][1] + (cnt[i] << i), dp[i][0]);
                dp[i][1] = max(dp[i + 1][1] + ((N - cnt[i]) << i), dp[i][1]);
            } else
                dp[i][1] = max(dp[i + 1][1] + (cnt[i] << i), dp[i][1]);
        }
    }

    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}
