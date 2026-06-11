#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n, k, q;
    cin >> n >> k >> q;
    set<ll> s;
    ll a[n];
    rep(i, n) {
        cin >> a[i];
        s.emplace(a[i]);
    }
    ll ans = LINF;
    for (auto mn : s) {
        auto isOK = [&](ll mx) {
            int sum[n + 1] = {};
            rep(i, n) {
                sum[i + 1] = sum[i] + (a[i] <= mx);
            }
            int cnt = 0, pre = 0;
            rep(i, n) {
                if (a[i] < mn) {
                    cnt += max(0, min(i - pre - k + 1, sum[i] - sum[pre]));
                    pre = i + 1;
                }
            }
            cnt += max(0, min(n - pre - k + 1, sum[n] - sum[pre]));
            return q <= cnt;
        };
        ll ng = -1, ok = LINF;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (isOK(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans = min(ans, ok - mn);
    }
    cout << ans << endl;
    return 0;
}