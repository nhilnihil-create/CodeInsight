#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> x(n + 1), dp(n + 1, 1e9), tmp(1 << 26, 1e9);
    rep(i, 0, n) {
        x[i + 1] = x[i] ^ (1 << (s[i] - 'a'));
    }
    tmp[0] = 0;
    rep(i, 0, n) {
        dp[i + 1] = tmp[x[i + 1]] + 1;
        rep(j, 0, 26) {
            dp[i + 1] = min(dp[i + 1], tmp[x[i + 1] ^ (1 << j)] + 1);
        }
        tmp[x[i + 1]] = min(tmp[x[i + 1]], dp[i + 1]);
    }
    cout << dp[n] << endl;
    return 0;
}