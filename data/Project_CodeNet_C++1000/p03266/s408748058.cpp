#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, k;
    cin >> n >> k;
    int64_t ans = 0;
    map < int, int64_t > mods;
    for (int i = 1; i <= n; ++i)
        ++mods[i % k];
    for (int i = 1; i <= n; ++i) {
        if ((i % k) == ((k - (i % k)) % k)) 
            ans += mods[i % k] * mods[(k - (i % k)) % k];
    }
    cout << ans << '\n';
}
