#include <bits/stdc++.h>
using namespace std;

int64_t f (int64_t x, int64_t i) {
    int64_t ans = (int64_t(1) << i) * (x >> (i + 1));
    if (x % (int64_t(1) << (i + 1)) >= (int64_t(1) << i))
        ans += x % (int64_t(1) << (i + 1)) - (int64_t(1) << i) + 1;
    return ans;
}

signed main () {
    int64_t a, b;
    cin >> a >> b;
    int64_t ans = 0;
    for (int64_t i = 0; i < 40; ++i) 
        ans += int64_t(((f(b, i) - f(max(a - 1, int64_t(0)), i)) & 1)) * (int64_t(1) << i);
    cout << ans << '\n';
}
