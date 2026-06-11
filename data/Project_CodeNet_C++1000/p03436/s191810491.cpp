#include <bits/stdc++.h>
using namespace std;

const vector<int> dy = {0, -1, 0, 1};
const vector<int> dx = {1, 0, -1, 0};

vector<vector<int>> dis;

void bfs(const vector<string>& s, int sy, int sx) {
    queue<pair<int, int>> que;
    que.emplace(sy, sx);
    dis.assign(s.size(), vector<int>(s[0].size(), -1));
    dis[sy][sx] = 0;
    while (!que.empty()) {
        int y, x;
        tie(y, x) = que.front(); que.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny < s.size() && nx >= 0 && nx < s[0].size() && dis[ny][nx] < 0 && s[ny][nx] == '.') {
                dis[ny][nx] = dis[y][x] + 1;
                que.emplace(ny, nx);
            }
        }
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    int black = 0;
    for (int i = 0; i < H; ++i) {
        cin >> s[i];
        for (int j = 0; j < W; ++j) {
            if (s[i][j] == '#') black++;
        }
    }
    bfs(s, 0, 0);
    cout << (dis[H - 1][W - 1] < 0 ? -1 : H * W - (dis[H - 1][W - 1] + 1) - black) << endl;
}