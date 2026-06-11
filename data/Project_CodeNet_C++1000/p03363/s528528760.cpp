#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, x;
    cin >> n;
    map < int64_t, int > cnt;
    ++cnt[0];
    int64_t ans = 0, p = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        p += x;
        ans += cnt[p];
        ++cnt[p];
    }
    cout << ans << '\n';
}
