#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1LL << 34;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, Q; cin >> A >> B >> Q;
    vector<ll> s(A+2), t(B+2);
    for (int i = 1; i <= A; i++) cin >> s[i];
    for (int i = 1; i <= B; i++) cin >> t[i];
    s[A+1] = t[B+1] = INF;

    for (int i = 0; i < Q; i++) {
        ll x; cin >> x;
        int si = lower_bound(s.begin(), s.end(), x)
               - s.begin();
        int ti = lower_bound(t.begin(), t.end(), x)
               - t.begin();
        ll sl = x - s[si-1], sr = s[si] - x;
        ll tl = x - t[ti-1], tr = t[ti] - x;

        ll ans = INF;
        if (si != 1 && ti != 1)
            ans = min(ans, max(sl, tl));
        if (si != A+1 && ti != B+1)
            ans = min(ans, max(sr, tr));
        if (si != 1 && ti != B+1)
            ans = min(ans, sl + tr + min(sl, tr));
        if (si != A+1 && ti != 1)
            ans = min(ans, sr + tl + min(sr, tl));
        cout << ans << "\n";
    }
}