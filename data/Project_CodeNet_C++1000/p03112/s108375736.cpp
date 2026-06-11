#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B);
    rep(i, A) cin >> s[i];
    rep(i, B) cin >> t[i];
    ll x;
    vector<int> a(2), b(2);
    rep(i, Q) {
        cin >> x;
        int j = lower_bound(s.begin(), s.end(), x) - s.begin();
        a[0] = max(0, j - 1), a[1] = min(j, A - 1);
        j = lower_bound(t.begin(), t.end(), x) - t.begin();
        b[0] = max(0, j - 1), b[1] = min(j, B - 1);
        ll ans = 1e18;
        rep(j, 2) {
            rep(k, 2) {
                ans = min(ans, abs(x - s[a[j]]) + abs(s[a[j]] - t[b[k]]));
                ans = min(ans, abs(x - t[b[k]]) + abs(s[a[j]] - t[b[k]]));
            }
        }
        cout << ans << "\n";
    }
}