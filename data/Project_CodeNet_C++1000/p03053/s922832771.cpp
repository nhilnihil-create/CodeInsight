#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> field(H);
    for (int h = 0; h < H; h++) {
        cin >> field[h];
    }

    // 全黒マスからの距離
    int dist[1000][1000];
    memset(dist, -1, sizeof(dist));

    // 探索対象のキュー
    queue<pair<int, int>> que;

    // とりあえず黒マスを全部キューに入れる
    for (int h = 0; h < H; h++) {
        for ( int w = 0; w < W; w++) {
            if (field[h][w] == '#'){
                que.push(make_pair(h, w));
                dist[h][w] = 0;
            }
        }
    }

    // 探索開始！
    while (!que.empty()) {
        pair<int, int> p = que.front();
        que.pop();

        // cout << p.first << " " << p.second << endl;

        for (int i = 0; i < 4; i++) {
            int nh = p.first + dy[i];
            int nw = p.second + dx[i];

            // cout << "nh, nw = " << nh << " " << nw << endl;

            // 範囲外だったらスルー
            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            // cout << "here?1" << endl;
            // 黒だったらスルー
            if (field[nh][nw] == '#') continue;
            // cout << "here?2" << endl;
            // 探索ずみならスルー
            if (dist[nh][nw] != -1) continue;
            // cout << "here?3" << endl;

            // cout << "here?" << endl;

            dist[nh][nw] = dist[p.first][p.second] + 1;
            que.push(make_pair(nh, nw));
        }
    }

    int max_dist = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            // cout << dist[h][w] << endl;
            max_dist = max(max_dist, dist[h][w]);
        }
    }

    cout << max_dist << endl;
}
