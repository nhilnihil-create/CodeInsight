#include <bits/stdc++.h>
using namespace std;

void chmax (int64_t &x, int64_t a) {
    x = max(x, a);
}

signed main () {
    int64_t n, m, ans = 0;
    cin >> n >> m;
    for (int64_t i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            if (i >= n) 
                chmax(ans, m / i);
            else if (m / i >= n)
                chmax(ans, i);
        }
    }
    cout << ans << '\n';
}
