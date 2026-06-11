#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; ++i) {
        cin >> a[i];
    }

    int dis[1010][1010];
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            dis[i][j] = INF;
        }
    }

    queue<pii> que;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (a[i][j] == '#') {
                que.push(pii(i, j));
                dis[i][j] = 0;
            }
        }
    }

    while (!que.empty()) {
        pii p = que.front();
        que.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = p.first + dx[k];
            int ny = p.second + dy[k];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (a[nx][ny] == '#' || dis[nx][ny] != INF) continue;
            que.push(pii(nx, ny));
            dis[nx][ny] = dis[p.first][p.second] + 1;
        }
    }

    int res = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            res = max(res, dis[i][j]);
        }
    }
    cout << res << endl;
}
