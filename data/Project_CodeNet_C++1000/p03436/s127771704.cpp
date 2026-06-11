#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using coord = pair<int, int>;

int dw[4] = {1, 0, -1, 0};
int dh[4] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i = 0; i < H; i++) {
        cin >> s[i];
    }

    queue<coord> que;
    vector<vector<int>> dist(H, vector<int>(W, -1));
    que.emplace(0, 0);
    dist[0][0] = 1;
    while (!que.empty()) {
        int h = que.front().first;
        int w = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int h_tmp = h - dh[i];
            int w_tmp = w - dw[i];
            if (h_tmp < 0 || h_tmp >= H || w_tmp < 0 || w_tmp >= W) continue;
            if (s[h_tmp][w_tmp] == '#') continue;
            if (dist[h_tmp][w_tmp] != -1) continue;
            que.emplace(h_tmp, w_tmp);
            dist[h_tmp][w_tmp] = dist[h][w] + 1;
        }
    }

    int white = 0, black = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (s[h][w] == '.') {
                white++;
            } else {
                black++;
            }
            // cout << dist[h][w] << " ";
        }
        // cout << endl;
    }

    int output;
    output = white - dist[H - 1][W - 1];
    if (dist[H - 1][W - 1] == -1) {
        output = -1;
    }
    cout << output << endl;

    return 0;
}
