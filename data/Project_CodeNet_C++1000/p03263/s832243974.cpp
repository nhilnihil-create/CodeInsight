#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int a[h][w];
    rep(y, h) rep(x, w) cin >> a[y][x];
    vector<vector<int>> actions;

    int ans = 0;
    rep(y, h) rep(x, w) {
        if (a[y][x] % 2 == 0 || (y == h - 1 && x == w - 1)) continue;

        int dy = y + 1, dx = x + 1;
        if (dx < w && a[y][dx] % 2 == 1) {
            a[y][x]--;
            a[y][dx]++;
            actions.push_back({y + 1, x + 1, y + 1, dx + 1});
        } else if (dy < h && a[dy][x] % 2 == 1) {
            a[y][x]--;
            a[dy][x]++;
            actions.push_back({y + 1, x + 1, dy + 1, x + 1});
        } else if (dx < w) {
            a[y][x]--;
            a[y][dx]++;
            actions.push_back({y + 1, x + 1, y + 1, dx + 1});
        } else if (dy < h) {
            a[y][x]--;
            a[dy][x]++;
            actions.push_back({y + 1, x + 1, dy + 1, x + 1});
        }

        ans++;
    }

    cout << ans << endl;
    for (auto e : actions) {
        rep(i, 3) cout << e[i] << ' ';
        cout << e[3] << endl;
    }
    return 0;
}
