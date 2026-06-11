#include<bits/stdc++.h>

using namespace std;


const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int H, W; 
vector<string> maze;


void solve() {
    cin >> H >> W;
    maze.resize(H);
    for (int i = 0; i < H; i++) cin >> maze[i];

    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < H; i++) {
        for (int  j = 0; j < W; j++) {
            if (maze[i][j] == '#') {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    int res = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            res = max(res, dist[i][j]);
        }
    }

    cout << res << endl;
}


int main() {
    solve();
    return 0;
}