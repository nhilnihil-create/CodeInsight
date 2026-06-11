#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k;
    cin>>n>>k;
    vector<ll> as(n);
    rep(i, n) cin>>as[i];
    vector<ll> cnt(50);
    ll md = 0;
    rep(d, 50) rep(i, n) {
        if (as[i]>>d&1) cnt[d]++;
        if (k>>d&1) md = d;
    }
    ll base = 1;
    rep(i, 49) base *= 2;
    vector<vector<ll>> dp(51, vector<ll>(2));
    for (int d = 49; d >= 0; --d) {
        ll kd = k>>d&1;
        rep(i, 2) rep(j, 2) {
            int ni = i;
            if (j > kd && !i) continue;
            if (i && d > md) continue;
            if (i && d == md && j) continue;
            if (j < kd && !i) ni = 1;
            if (j)
                dp[d][ni] = max(dp[d][ni], dp[d + 1][i] + (n - cnt[d]) * base);
            else
                dp[d][ni] = max(dp[d][ni], dp[d + 1][i] + cnt[d] * base);
        }
        base /= 2;
    }
    cout<<max(dp[0][0], dp[0][1])<<endl;
}