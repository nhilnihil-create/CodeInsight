#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int h, w;
vector<vector<char>> maze(51, vector<char>(51));
vector<vector<bool>> reached(51, vector<bool>(51, false));
vector<vector<int>> dist(51, vector<int>(51, -1));

int dy[] = {1, 0, 0, -1};
int dx[] = {0, -1, 1, 0};

int bfs(int sy, int sx) {
    rep(i, h) {
        rep(j, w) {
            dist[i][j] = -1;
        }
    }

    dist[sy][sx] = 0;
    queue<P> q;
    q.push(make_pair(sy, sx));

    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();
        rep(i, 4) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (dist[ny][nx] != -1) continue;
            if (ny == h-1 && nx == w-1) {
                dist[ny][nx] = dist[y][x] + 1;
                break;
            }
            if (maze[ny][nx] != '#') {
                q.push(make_pair(ny, nx));
                dist[ny][nx] = dist[y][x] + 1;
            } 
        }
    }
    return dist[h-1][w-1];
}
 
int main() {
    cin >> h >> w;

    int black = 0;
    rep(i, h) {
        rep(j, w) {
            cin >> maze[i][j];
            if (maze[i][j] == '#') {
                black++;
            }
        }
    }
    
    int ans = bfs(0, 0);
    if (ans == -1) {
        cout << ans << endl;
    } else {
        cout << w * h - black - ans - 1 << endl;
    }

    return 0;
}