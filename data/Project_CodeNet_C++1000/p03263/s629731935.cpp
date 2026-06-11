#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int a[505][505];
vector<vector<int>> actions;

void moveCoin(int y, int x, int dy, int dx) {
    a[y][x]--;
    a[dy][dx]++;
    actions.push_back({y + 1, x + 1, dy + 1, dx + 1});
}

int main() {
    int h, w;
    cin >> h >> w;
    rep(y, h) rep(x, w) cin >> a[y][x];

    int ans = 0;
    rep(y, h) rep(x, w) {
        if (a[y][x] % 2 == 0 || (y == h - 1 && x == w - 1)) continue;

        int dy = y + 1, dx = x + 1;
        if (dx < w && a[y][dx] % 2 == 1)
            moveCoin(y, x, y, dx);
        else if (dy < h && a[dy][x] % 2 == 1)
            moveCoin(y, x, dy, x);
        else if (dx < w)
            moveCoin(y, x, y, dx);
        else if (dy < h)
            moveCoin(y, x, dy, x);

        ans++;
    }

    cout << ans << endl;
    for (auto e : actions) {
        rep(i, 3) cout << e[i] << ' ';
        cout << e[3] << endl;
    }
    return 0;
}
