#include <bits/stdc++.h>
using namespace std;

const int64_t inf = 1e18;

signed main () {
    int n, m;
    cin >> n >> m;
    vector < int64_t > x(n), y(n), z(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> z[i];
    int64_t ans = 0;
    for (int mask = 0; mask < 8; ++mask) {
        vector < int64_t > prior(n, 0);
        for (int i = 0; i < n; ++i) {
            prior[i] = x[i] + y[i] + z[i];
            if (mask & (1 << 0))
                prior[i] -= 2 * x[i];
            if (mask & (1 << 1))
                prior[i] -= 2 * y[i];
            if (mask & (1 << 2))
                prior[i] -= 2 * z[i];
        }
        sort(prior.rbegin(), prior.rend());
        int64_t here = 0;
        for (int i = 0; i < m; ++i)
            here += prior[i];
        ans = max(ans, here);
    }
    cout << ans << '\n';
}
