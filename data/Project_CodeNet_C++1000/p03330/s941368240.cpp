#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 37;

int d[31][31], g[501][501];
vector < vector < int > > cnt(3, vector < int > (31, 0));

signed main () {
	int n, c;
    cin >> n >> c;
    for (int i = 1; i <= c; ++i) {
        for (int j = 1; j <= c; ++j)
            cin >> d[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
            ++cnt[(i + j) % 3][g[i][j]];
        }
    }
    int ans = inf;
    for (int i = 1; i <= c; ++i) {
        for (int j = 1; j <= c; ++j) {
            for (int w = 1; w <= c; ++w) {
                if (i != j && j != w && i != w) {
                    int cur = 0;
                    for (int y = 1; y <= c; ++y) 
                        cur += d[y][i] * cnt[0][y];
                    for (int y = 1; y <= c; ++y) 
                        cur += d[y][j] * cnt[1][y];
                    for (int y = 1; y <= c; ++y) 
                        cur += d[y][w] * cnt[2][y];
                    ans = min(ans, cur);
                }
            }
        }
    }
    cout << ans << '\n';
}
