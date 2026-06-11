#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];

    mat dist(h, vec(w, INF));
    queue<P> que;
    
    rep(i, h) rep(j, w) {
        if (g[i][j] == '#') {
            dist[i][j] = 0;
            que.push({i, j});
        }
    }

    while (!que.empty()) {
        auto fr = que.front();
        que.pop();

        rep(i, 4) {
            int ty = fr.first + dy[i];
            int tx = fr.second + dx[i];

            if (ty >= 0 && ty < h && tx >= 0 && tx < w) {
                if (g[ty][tx] == '.' && dist[ty][tx] > dist[fr.first][fr.second] + 1) {
                    dist[ty][tx] = dist[fr.first][fr.second] + 1;
                    que.push({ty, tx});
                }
            }
        }
    }

    int mx = 0;

    rep(i, h) rep(j, w) mx = max(mx, dist[i][j]);
    cout << mx << endl;
    return 0;
}