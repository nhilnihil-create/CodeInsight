#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vvi a(n, vi(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    vector<ll> dp(1 << n);
    for(int b = 1; b < 1 << n; b++) {
        ll r = 0;
        rep(i, n) rep(j, i) if (b >> i & b >> j & 1) {
            r += a[i][j];
        }
        for(int s = b; s >= 0; s--) {
            s &= b;
            chmax(r, dp[s] + dp[s^b])
        }
        dp[b] = r;
    }
    cout << dp.back() << endl;
}