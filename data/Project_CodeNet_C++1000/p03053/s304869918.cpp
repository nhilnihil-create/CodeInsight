#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = 1e8;

int H, W;

ll dist[1010][1010];

char maze[1010][1010];


void bfs() {
    // cout << sy << " " << sx << endl;

    queue<P> q;

    rep(i, H)rep(j, W) {
        if (maze[i][j] == '.') continue;
        dist[i][j] = 0;
        q.push(P(i, j));
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!q.empty()) {
        P p = q.front(); q.pop();
        // if (p.first == gy && p.second == gx) break;
        for (int i = 0; i < 4; i++) {
            int nx = p.second + dx[i], ny = p.first + dy[i];
            if (0 <= ny && ny < H && 0 <= nx && nx < W && maze[ny][nx] != '#' && dist[ny][nx] == INF) {
                    // cout << ny << " " << nx << endl;
                    q.push(P(ny, nx));
                    dist[ny][nx] = dist[p.first][p.second] + 1;
            }
        }
    }
}

int main() {
    cin >> H >> W;

    rep(i, H)rep(j, W) cin >> maze[i][j];

    // # 開始から最大の距離 の中で一番小さい値
    rep(i2, H)rep(j2, W) dist[i2][j2] = INF;


    bfs();

    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (dist[i][j] == INF) continue;
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans << endl;
}