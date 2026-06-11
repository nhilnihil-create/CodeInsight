#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i=0; i<h; i++) cin >> a[i];

    // 多点スタート
    // スタートから0距離で到達できる場合には距離配列に0を格納
    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<pair<int, int>> que;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (a[i][j] == '#') {
                dist[i][j] = 0;
                que.push(pair<int, int>(i,j));
            }
        }
    }

    while(!que.empty()) {
        auto cur = que.front();
        que.pop();
        for (int i=0; i<4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if (dist[nx][ny]==-1) {
                que.push(pair<int, int>(nx, ny));
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
            }
        }
    }

    int res = 0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            res = max(res, dist[i][j]);
        }
    }
    
    cout << res << endl;

    return 0;
}