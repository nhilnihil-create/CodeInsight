#include <bits/stdc++.h>
using namespace std;
 
signed main () {
    int n;
    cin >> n;
    vector < int > c(n - 1), s(n - 1), f(n - 1);
    for (int i = 0; i < n - 1; ++i)
        cin >> c[i] >> s[i] >> f[i];
    for (int i = 0; i < n; ++i) {
        int64_t ans = 0;
        for (int j = i; j < n - 1; ++j) {
            ans = max(ans, int64_t(s[j]));
            while (ans % f[j])
                ++ans;
            ans += c[j];
        }
        cout << ans << '\n';
    }
}
