#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int dx[] = {0,  0,  1, -1};
const int dy[] = {1, -1,  0,  0};

int main() {
    int H, W; cin >> H >> W;
    vector<string> s(H);
    for (int i = 0; i < H ; i++) {
        cin >> s[i];
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        int x = v.first, y = v.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= H) continue;
            if (ny < 0 || ny >= W) continue;
            if (s[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    if (dist[H-1][W-1] == -1) {
        cout << -1 << endl;
        return 0;
    }

    int tot = H * W;
    int cnt = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '#') cnt++;
        }
    }
    cout << tot - cnt - dist[H-1][W-1] - 1 << endl;
}
