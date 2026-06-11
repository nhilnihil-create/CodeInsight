#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a+2), t(b+2);
    s[0] = t[0] = -INF;
    s[a+1] = t[b+1] = INF;
    rep1(i, a+1) cin >> s[i];
    rep1(i, b+1) cin >> t[i];
    rep(i, q) {
        ll x; cin >> x;
        ll ans = INF;
        int si = lower_bound(all(s), x) - s.begin();
        int ti = lower_bound(all(t), x) - t.begin();
        for (int j = si-1; j <= si; j++) {
            for (int k = ti-1; k <= ti; k++) {
                ll S = s[j];
                ll T = t[k];
                ans = min(ans, abs(S-x) + abs(T - S));
                ans = min(ans, abs(T-x) + abs(S - T));
            }
        }
        cout << ans << endl;
    }
    return 0;
}