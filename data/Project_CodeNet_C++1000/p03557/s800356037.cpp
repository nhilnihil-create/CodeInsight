#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll a[n], b[n], c[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);

    ll ans = 0;
    rep(i, n) {
        ll lower = lower_bound(a, a + n, b[i]) - a;
        ll upper = n + c - upper_bound(c, c + n, b[i]);
        ans += lower * upper;
    }

    cout << ans << endl;
    return 0;
}
