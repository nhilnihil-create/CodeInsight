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

    string S;
    cin >> S;

    int N = S.length();
    vector<vector<ll>> dp(N + 1, vector<ll>(3));
    ll cnt = 1;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'A' || S[i] == '?')
            dp[i + 1][0] += cnt;
        if (S[i] == 'B' || S[i] == '?')
            dp[i + 1][1] += dp[i][0];
        if (S[i] == 'C' || S[i] == '?')
            dp[i + 1][2] += dp[i][1];
        for (int j = 0; j < 3; ++j) {
            if (S[i] == '?') {
                dp[i + 1][j] += dp[i][j] * 3;
            } else
                dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
        }
        if (S[i] == '?')
            (cnt *= 3) %= MOD;
    }

    cout << dp[N][2] << endl;

    return 0;
}
