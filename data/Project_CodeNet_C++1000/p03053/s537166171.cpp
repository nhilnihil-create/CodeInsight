#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int h, w;
vector<string> field(1005);

int dy[] = {1, 0, 0, -1};
int dx[] = {0, -1, 1, 0};


int main() {
    cin >> h >> w;
    rep(i, h){
        cin >> field[i];
    }

    vector<vector<int>> dist(h, vector<int>(w, -1));
    queue<P> q;
    rep(i, h) {
        rep(j, w) {
            if (field[i][j] == '#') {
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        rep(i, 4) {
            int ny = cur.first + dy[i], nx = cur.second + dx[i];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (dist[ny][nx] == -1) {
                dist[ny][nx] = dist[cur.first][cur.second] + 1;
                q.push(make_pair(ny, nx));
            }
        } 
    }

    int ans = 0;
    rep(i, h) {
        rep(j ,w) {
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}