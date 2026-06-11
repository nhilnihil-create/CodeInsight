#include <bits/stdc++.h>
using namespace std;

signed main () {
    int n, k;
    cin >> n >> k;
    int64_t ans = 0;
    for (int b = k + 1; b <= n; ++b) {
        ans += int64_t(n / b) * int64_t(b - k);
        if (n % b >= k)
            ans += (n % b) - k + 1 - int(k == 0);
    }
    cout << ans << '\n';
}
