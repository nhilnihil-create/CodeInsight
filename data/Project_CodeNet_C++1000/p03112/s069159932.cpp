#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

const int N = 1e5 + 5;
ll s[N], t[N], res[N];
ll a, b, q, x;
ll l1, r1, l2, r2;
int main() {
    cin >> a >> b >> q;
    for (int i = 0; i < a; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < b; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> x;
        auto it = lower_bound(s, s + a, x);
        if (it != s + a) {
            r1 = *it - x;
        } else {
            r1 = 1e15;
        }
        if (it != s) {
            l1 = x - *(it - 1);
        } else {
            l1 = 1e15;
        }

        it = lower_bound(t, t + b, x);
        if (it != t + b) {
            r2 = *it - x;
        } else {
            r2 = 1e15;
        }
        if (it != t) {
            l2 = x - *(it - 1);
        } else {
            l2 = 1e15;
        }
        // cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;
        ll ans = min(max(r1, r2), max(l1, l2));
        if (l1 > r2) {
            ans = min(ans, r2 * 2 + l1);
        } else {
            ans = min(ans, l1 * 2 + r2);
        }
        if (r1 > l2) {
            ans = min(ans, l2 * 2 + r1);
        } else {
            ans = min(ans, r1 * 2 + l2);
        }
        res[i] = ans;
    }
    for (int i = 0; i < q; ++i) {
        cout << res[i] << endl;
    }
    return 0;
}
