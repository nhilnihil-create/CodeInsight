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
    vi concerned;
    for(int b = 1; b < 1 << n; b++) {
        concerned.resize(0);
        rep(k, n) {
            if (b >> k & 1) {
                concerned.push_back(k);
            }
        }
        int sz = concerned.size();
        ll tot = 0;
        rep(i, sz) rep(j, i) {
            int x = concerned[i], y = concerned[j];
            tot += a[x][y];
        }
        chmax(dp[b], tot);
        int r0 = 1 << concerned.back();
        concerned.pop_back(); sz--;
        for(int c = 1; c < 1 << sz; c++) {
            int l = 0, r = r0;
            rep(i, sz) {
                int k = concerned[i];
                if (c >> i & 1) l |= 1 << k;
                else r |= 1 << k;
            }
            chmax(dp[b], dp[l] + dp[r]);
        }
    }
    cout << dp.back() << endl;
}