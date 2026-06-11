#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
using pint = pair<int,int>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int H, W;
string fi[110];
int dist[110][110]; // BFS 用

int main() {
    // 入力
    cin >> H >> W;
    int wnum = 0;
    for (int i = 0; i < H; ++i) {
        cin >> fi[i];
        for (int j = 0; j < W; ++j) {
            if (fi[i][j] == '.') ++wnum;
        }
    }

    // BFS
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 1;
    queue<pint> que;
    que.push(pint(0, 0));
    while (!que.empty()) {
        pint cur = que.front();
        que.pop();
        int x = cur.first;
        int y = cur.second;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (fi[nx][ny] == '#') continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                que.push(pint(nx, ny));
            }
        }
    }
    if (dist[H-1][W-1] == -1) cout << -1 << endl;
    else  cout << wnum - dist[H-1][W-1] << endl;
}