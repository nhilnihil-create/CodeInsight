#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)

const int maxn = 5e5 + 1, mod = 1e9 + 7;

using namespace std;

bool v[1000][1000];
int d[1000][1000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char ch; cin >> ch;
            v[i][j] = (ch == '#');
        }
    }
    queue<pi> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            d[i][j] = v[i][j];
            if (d[i][j]) q.push({i, j});
        }
    int ans = 0;
    while (!q.empty()) {
        int x = q.front().l;
        int y = q.front().r;
        q.pop();
        if (x && !d[x - 1][y]) {
            d[x - 1][y] = d[x][y] + 1;
            q.push({x - 1, y});
        }
        if (x < n - 1 && !d[x + 1][y]) {
            d[x + 1][y] = d[x][y] + 1;
            q.push({x + 1, y});
        }
        if (y && !d[x][y - 1]) {
            d[x][y - 1] = d[x][y] + 1;
            q.push({x, y - 1});
        }
        if (y < m - 1 && !d[x][y + 1]) {
            d[x][y + 1] = d[x][y] + 1;
            q.push({x, y + 1});
        }
        ans = max(ans, d[x][y]);
    }
    cout << ans - 1;
    return 0;
}
