#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 1e6;

signed main () {
    int n;
    cin >> n;
    vector < int > x(n), y(n), h(n);
    pair < int, pair < int, int > > check = make_pair(inf, make_pair(-1, -1));
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> h[i];
        if (h[i])
            check = min(check, make_pair(h[i], make_pair(x[i], y[i])));
    }
    for (int cx = 0; cx <= 100; ++cx) {
        for (int cy = 0; cy <= 100; ++cy) {
            int cur_h = 1;
            if (check.first < inf)
                cur_h = check.first + abs(check.second.first - cx) + abs(check.second.second - cy);
            bool ok = 1;
            for (int i = 0; i < n; ++i) {
                if (max(cur_h - abs(x[i] - cx) - abs(y[i] - cy), 0) != h[i])
                    ok = 0;
            }
            if (ok) {
                cout << cx << ' ' << cy << ' ' << cur_h << '\n';
                return 0;
            }
        }
    }
}
