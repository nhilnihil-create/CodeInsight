#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        ll a, b;
        cin >> a >> b;
        ll c = a * b, ans = 0;
        if (c < 3) {
            cout << 0 << '\n';
            continue;
        }
        if (a == b) {
            cout << a + b - 2 << '\n';
            continue;
        }
        if (a < b) {
            swap(a, b);
        }
        if (a == b + 1) {
            cout << 2 * b - 2 << '\n';
            continue;
        }
        ans = (b - 1);
        ll t = c / (a + 1);
        ans += t;
        ll lo = 0, hi = a - b + 1;
        debug(t);
        while (hi - lo > 1) {
            ll mid = (lo + hi) / 2;
            if (t + mid < b + 1) {
                ll x = (t + mid) * (b + 1);
                if (x < c) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            } else {
                ll x = (t + b + mid + 1) / 2;
                ll y = x + (t + b + mid + 1) % 2;
                if (x * y < c) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
        }
        ans += lo;
        cout << ans << '\n';
    }
    return 0;
}
