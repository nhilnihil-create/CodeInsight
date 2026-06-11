#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {

    int h, w; cin >> h >> w;

    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }

    queue<pair<int, int>> q;

    vector<vector<int>> d(h, vector<int>(w, -1));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') {
                d[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
            if (d[nx][ny] != -1) continue;

            d[nx][ny] = d[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ans = max(ans, d[i][j]);
        }
    }

    cout << ans << endl;
}