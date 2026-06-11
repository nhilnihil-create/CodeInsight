#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];
    vector<vector<int>> G(H * W + 1);
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    rep(i, H) rep(j, W) rep(k, 4) {
        if (0 <= i + dx[k] && i + dx[k] < H && 0 <= j + dy[k] && j + dy[k] < W) {
            G[i * W + j].push_back((i + dx[k]) * W + j + dy[k]);
        }
    }
    rep(i, H) rep(j, W) {
        if (A[i][j] == '#') {
            G[H * W].push_back(i * W + j);
            G[i * W + j].push_back(H * W);
        }
    }
    vector<int> dist(H * W + 1, -1);
    dist[H * W] = 0;
    queue<int> q;
    q.push(H * W);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int ans = 0;
    rep(i, H * W) ans = max(ans, dist[i]);
    cout << ans - 1 << "\n";
    return 0;
}
