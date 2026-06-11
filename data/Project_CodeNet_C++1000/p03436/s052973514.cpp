//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> s(H, vector<bool>(W,false)); // 黒はfalse
    int num_white = 0;
    rep(i,0,H) rep(j,0,W) {
        char c;
        cin >> c;
        if (c == '.') { s[i][j] = true; num_white++; }
    }

    // ans = num_white - 最短経路長
    queue<pair<int,int>> q;
    vector<vector<int>> dist(H, vector<int>(W,-1));
    dist[0][0] = 0;
    q.push({0,0});
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    while (!q.empty()) {
        int y = q.front().first, x = q.front().second;
        q.pop();
        rep(i,0,4) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx < 0 || W <= nx || ny < 0 || H <= ny) continue;
            if (dist[ny][nx] != -1) continue;
            if (!s[ny][nx]) continue;
            q.push({ny,nx});
            dist[ny][nx] = dist[y][x] + 1;
        }
    }

    if (dist[H-1][W-1] == -1) cout << -1 << endl;
    else cout << num_white - dist[H-1][W-1] - 1 << endl;
}