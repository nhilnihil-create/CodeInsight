#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define MOD 1000000007
int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n+1, vector<int>(1 << n));
    dp[0][0] = 1;
    rep(i, n) rep(j, n) {
        int a;
        cin >> a;
        if (a) rep(s, 1 << n) if ((s >> j & 1) == 0) {
            dp[i+1][s | 1 << j] += dp[i][s];
            dp[i+1][s | 1 << j] %= MOD;
        }
    }
    cout << dp[n][(1 << n) - 1] << endl;
}
