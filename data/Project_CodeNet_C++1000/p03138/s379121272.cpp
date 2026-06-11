#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

ll dp[45][2];

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(41);
    rep(i,41) {
        rep(j,n) {
            cnt[i] += a[j]>>i&1;
        }
    }
    
    rep(i,42)rep(j,2) dp[i][j] = -1;
    dp[41][0] = 0;

    ll t = pow(2,40);
    for (int i = 40; i >= 0; i--) {
        if (k>>i&1) {
            dp[i][0] = dp[i+1][0] + t*(n-cnt[i]);
            dp[i][1] = dp[i+1][0] + t*cnt[i];
        }
        else {
            dp[i][0] = dp[i+1][0] + t*cnt[i];
        }
        if (dp[i+1][1] != -1) {
            int d = max(cnt[i], n-cnt[i]);
            dp[i][1] = max(dp[i][1], dp[i+1][1] + t*d);
        }
        t /= 2;
    }
    ll ans = max(dp[0][0], dp[0][1]);
    cout << ans << endl;
    return 0;
}