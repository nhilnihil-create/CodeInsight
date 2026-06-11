#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> z(w + 2);
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        if (x >= y)
            z[y].emplace_back(x);
    }
    rep(i, 1, w + 1) sort(z[i].begin(), z[i].end());
    int ans = h;
    int x = 1, y = 1;
    for (; x <= h; x++) {
        //debug(x, y);
        int p = h + 1;
        if (z[y].size() != 0) {
            auto it = lower_bound(z[y].begin(), z[y].end(), x + 1);
            if (it != z[y].end()) p = *it;
        }
        if (p == x + 1) {
            ans = min(ans, x);
        } else if (z[y + 1].size() == 0 || upper_bound(z[y + 1].begin(), z[y + 1].end(), x + 1) - lower_bound(z[y + 1].begin(), z[y + 1].end(), x + 1) == 0) {
            if (y != w) y++;
        }
        ans = min(p - 1, ans);
        if (y == w || x >= ans) break;
    }

    cout << ans << endl;
    return 0;
}