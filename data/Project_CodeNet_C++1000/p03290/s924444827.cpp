#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 37;

signed main () {
    int d, g;
    cin >> d >> g;
    vector < int > p(d), c(d);
    for (int i = 0; i < d; ++i)
        cin >> p[i] >> c[i];
    int ans = inf;
    for (int mask = 0; mask < (1 << d); ++mask) {
        int here = 0, cur = 0;
        multiset < int > gang;
        for (int i = 0; i < d; ++i) {
            if (mask & (1 << i)) 
                here += p[i] * 100 * (i + 1) + c[i], cur += p[i];
            else {
                for (int j = 0; j < p[i]; ++j)
                    gang.insert(100 * (i + 1));
            }
        }
        while (!gang.empty() && here < g) {
            here += *prev(gang.end());
            gang.erase(prev(gang.end()));
            ++cur;
        }
        if (here >= g)
            ans = min(ans, cur);
    }
    cout << ans << '\n';
}
