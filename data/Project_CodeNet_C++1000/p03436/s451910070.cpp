#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 4 方向への移動 (下、右、上、左)
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) cin >> S[i];

    // dist[x][y] = マス (x, y) への最短距離
    // キューの各要素は、マス (x, y) を表すペアとする
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int,int>> que;

    // 初期条件
    dist[0][0] = 0;
    que.push({0, 0});

    // 幅優先探索
    while (!que.empty()) {
        pair<int,int> v = que.front();
        que.pop();
        int x = v.first, y = v.second;
        for (int dir = 0; dir < 4; ++dir) {
            int x2 = x + dx[dir], y2 = y + dy[dir];

            // 配列外参照はダメ、黒マスには行けない
            if (x2 < 0 || x2 >= H || y2 < 0 || y2 >= W || S[x2][y2] == '#') 
                continue;

            if (dist[x2][y2] != -1) continue;
            dist[x2][y2] = dist[x][y] + 1;
            que.push({x2, y2});
        }
    }

    // 残り白マス数をカウント
    int white = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (S[i][j] == '.') ++white;
        }
    }
    
    // 最短路に使う白マス数は dist[H-1][W-1] + 1
    if (dist[H-1][W-1] == -1) cout << -1 << endl;
    else cout << white - (dist[H-1][W-1] + 1) << endl;
}