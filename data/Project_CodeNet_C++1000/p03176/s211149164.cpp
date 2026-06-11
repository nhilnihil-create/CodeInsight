#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> h(n), a(n);
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> a[i];
    map<int, ll> dp;
    dp[0] = 0;
    rep(i, n) {
        auto it = dp.lower_bound(h[i]);
        it--;
        ll t = it->second + a[i];
        dp[h[i]] = t;
        while(1) {
            auto it = dp.upper_bound(h[i]);
            if (it != dp.end() && it->second <= t) {
                dp.erase(it);
            } else break;
        }
    }
    cout << dp.rbegin()->second << endl;
}
