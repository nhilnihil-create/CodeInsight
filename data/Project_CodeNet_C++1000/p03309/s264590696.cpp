#include <bits/stdc++.h>
using namespace std;

const int64_t inf = 1e15 + 3;

void chmin (int64_t &x, int64_t a) {
    x = min(x, a);
}

signed main () {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a.begin(), a.end());
    vector < int64_t > pref(n + 1, 0), suff(n + 1, 0);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + a[i];
    for (int i = n - 1; i >= 0; --i)
        suff[i] = suff[i + 1] + a[i];
    int64_t ans = inf;
    for (int i = 0; i < n; ++i) {
        int64_t here = (int64_t(i) * a[i] - pref[i]) + (suff[i + 1] - int64_t(n - 1 - i) * a[i]);
        chmin(ans, here);
    }
    cout << ans << '\n';
}
