#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb emplace
#define pi pair <int, int>
#define f first
#define s second
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0

char G[150][150];
int h, w, dist[150][150];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
queue <pi> q;

void bfs() {
    memset(dist, -1, sizeof(dist));
    pi source = make_pair(1, 1);
    dist[source.f][source.s] = 0;
    q.pb(source.f, source.s);
    while (q.size()) {
        int y = q.front().f;
        int x = q.front().s;
        q.pop();
        for(int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny > h || ny < 1 || nx > w || nx < 1) continue;
            if (G[ny][nx] == '#') continue;
            if (dist[ny][nx] == -1) {
                q.emplace(ny, nx);
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int white = 0;
    cin >> h >> w;
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            cin >> G[i][j];
            if (G[i][j] == '.') ++white;
        }
    }
    bfs();
    if (dist[h][w] == -1) {
        cout << -1;
        time;
    }
    else {
        cout << white - dist[h][w] - 1;
        time;
    }
}