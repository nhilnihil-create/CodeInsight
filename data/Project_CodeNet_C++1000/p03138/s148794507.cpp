#include <bits/stdc++.h>
using namespace std;

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    int64_t k;
    cin >> n >> k;
    vector < int64_t > a(n);
    vector < int > cnt(40, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 40; ++j) {
            if (a[i] & (int64_t(1) << int64_t(j)))
                ++cnt[j];
        }
    }
    int64_t x = 0;
    for (int i = 39; i >= 0; --i) {
        if (cnt[i] < (n / 2 + (n & 1)) && x + (int64_t(1) << int64_t(i)) <= k)
            x += (int64_t(1) << int64_t(i));
    }
    int64_t ans = 0;
    for (int i = 0; i < n; ++i)
        ans = ans + (x ^ a[i]);
    cout << ans << '\n';
}
