#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 35;

void chmax (int &x, int y) {
    x = max(x, y);
}

signed main () {
    int n;
    cin >> n;
    vector < vector < bool > > f(n, vector < bool > (10, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            int x;
            cin >> x;
            f[i][j] = bool(x);
        }
    }
    vector < vector < int > > p(n, vector < int > (11));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 10; ++j)
            cin >> p[i][j];
    }
    int ans = -inf;
    for (int mask = 1; mask < (1 << 10); ++mask) {
        int ans_cur = 0;
        bool common = 0;
        for (int i = 0; i < n; ++i) {
            int w = 0;
            for (int j = 0; j < 10; ++j) {
                if (f[i][j] && (mask & (1 << j)))
                    ++w;
            }
            if (w) 
                common = 1;
            ans_cur += p[i][w];
        }
        if (common)
            chmax(ans, ans_cur);
    }
    cout << ans << '\n';
}
