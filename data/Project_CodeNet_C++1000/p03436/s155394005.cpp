//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

int main () {
    int h, w; cin >> h >> w;
    vector<string> maze(h);
    rep(i, h) cin >> maze[i];
    vector<vector<int>> d(h, vector<int> (w, -1));
    int black = 0;
    rep(i, h) rep(j, w) {
        if (maze[i][j] == '#') black++;
    }
    d[0][0] = 1;
    queue<P> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        int y = v.first, x = v.second;
        rep(i, 4) {
            int ny = y+dy[i], nx = x+dx[i];
            if (ny<0 || ny>=h || nx<0 || nx>=w || d[ny][nx]!=-1 || maze[ny][nx]=='#') continue;
            d[ny][nx] = d[y][x] + 1;
            q.push({ny, nx});
        }
    }
    if (d[h-1][w-1] == -1) {
        cout << -1 << endl;
        return 0;
    }
    cout << h*w - black - d[h-1][w-1] << endl;

    return 0;
}