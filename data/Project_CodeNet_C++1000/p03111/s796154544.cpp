#include <bits/stdc++.h>
#pragma GCC target("avx2")
using namespace std;

const int inf = 1e9 + 13;

signed main () {
    int n;
    cin >> n;
    vector < int > need(4);
    for (int i = 1; i < 4; ++i)
        cin >> need[i];
    vector < int > l(n);
    for (int i = 0; i < n; ++i)
        cin >> l[i];
    sort(l.rbegin(), l.rend());
    int ans = inf;
    for (int mask = 0; mask < (1 << (2 * n)); ++mask) {
        vector < int > sum(4);
        vector < int > cnt(4);
        int m = mask;
        for (int i = 0; i < n; ++i) {
            if (m & 3) {
                sum[m & 3] += l[i];
                ++cnt[m & 3];
            }
            m >>= 2;
        }
        int here = 0;
        bool can = 1;
        for (int i = 1; i <= 3; ++i) {
            if (cnt[i] == 0)
                can = 0;
            else 
                here += abs(need[i] - sum[i]) + (cnt[i] - 1) * 10;
        }
        if (can)
            ans = min(here, ans);
    }
    cout << ans << '\n';
}
