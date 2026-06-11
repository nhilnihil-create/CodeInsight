#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int N = S.length();
    vector<vector<int>> dp(N + 1, vector<int>(3));
    ll k = 1;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'A' || S[i] == '?') {
            (dp[i + 1][0] += dp[i][0] + k) %= MOD;
            (dp[i + 1][1] += dp[i][1]) %= MOD;
            (dp[i + 1][2] += dp[i][2]) %= MOD;
        }
        if (S[i] == 'B' || S[i] == '?') {
            (dp[i + 1][0] += dp[i][0]) %= MOD;
            int tmp = (dp[i][0] + dp[i][1]) % MOD;
            (dp[i + 1][1] += tmp) %= MOD;
            (dp[i + 1][2] += dp[i][2]) %= MOD;
        }
        if (S[i] == 'C' || S[i] == '?') {
            (dp[i + 1][0] += dp[i][0]) %= MOD;
            (dp[i + 1][1] += dp[i][1]) %= MOD;
            int tmp = (dp[i][1] + dp[i][2]) % MOD;
            (dp[i + 1][2] += tmp) %= MOD;
        }
        if(S[i] == '?')
            (k *= 3) %= MOD;
    }

    cout << dp[N][2] << endl;
    return 0;
}
