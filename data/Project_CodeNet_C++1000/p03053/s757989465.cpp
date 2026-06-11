#include <bits/stdc++.h>
using namespace std;

int h, w;
vector<string> field;
vector<vector<int>> times;
queue<pair<int, int>> q;
vector<vector<bool>> seen;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs () {
    while (!q.empty()) {
        int noy = q.front().first;
        int nox = q.front().second;
        q.pop();
        for (int i=0; i<4; ++i) {
            int ney = noy + dy[i];
            int nex = nox + dx[i];
            if (ney < 0 || h <= ney) continue;
            if (nex < 0 || w <= nex) continue;
            if (seen[ney][nex] == false) {
                q.push(make_pair(ney, nex));
                seen[ney][nex] = true;
                times[ney][nex] = times[noy][nox] + 1;
            }
        }
    }
}

int main() {
    cin >> h >> w;
    field.resize(h);
    times.resize(h, vector<int>(w, 1e9));
    seen.resize(h, vector<bool>(w, false));
    for (int i=0; i<h; ++i) cin >> field[i];
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            if (field[i][j] == '#') {
                times[i][j] = 0;
                seen[i][j] = true;
                q.push(make_pair(i, j));
            }
        }
    }
    bfs();
    int ans = 0;
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            ans = max(ans, times[i][j]);
        }
    }
    cout << ans << endl;
}