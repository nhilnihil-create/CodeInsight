#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int64_t inf = 4e18 + 11;

signed main () {
    int n, k;
    cin >> n >> k;
    vector < pair < int, int > > p(n);
    vector < int > f(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        f[i] = p[i].x;
        s[i] = p[i].y;
    }
    int64_t ans = inf;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            for (int v = i + 1; v < n; ++v) {
                for (int c = j + 1; c < n; ++c) {
                    int cnt = 0;
                    int l = min(f[i], f[v]), r = max(f[i], f[v]);
                    int d = min(s[j], s[c]), u = max(s[j], s[c]);
                    for (int w = 0; w < n; ++w) {
                        if (p[w].x >= l && p[w].x <= r && p[w].y >= d && p[w].y <= u)
                            ++cnt;
                    }
                    if (cnt >= k)
                        ans = min(ans, int64_t(r - l) * int64_t(u - d));
                }
            }
        }
    }
    cout << ans << '\n';
}
