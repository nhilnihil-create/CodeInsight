#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int H, W;
char c[60][60];
int dist[60][60];

int main() {
    cin >> H >> W;

    int cnt = 0;
    for (int h = 1; h <= H; ++h)
        for (int w = 1; w <= W; ++w) {
            cin >> c[h][w];
            if (c[h][w] == '.')
                ++cnt;
        }

    memset(dist, -1, sizeof(dist));
    dist[1][1] = 1;
    queue<pair<int, int>> Q;
    Q.push(make_pair(1, 1));

    int dh[] = {0, 0, 1, -1};
    int dw[] = {1, -1, 0, 0};

    while (!Q.empty()) {
        int h = Q.front().first, w = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; ++i) {
            int nh = h + dh[i], nw = w + dw[i];
            //if (c[nh][nw] == '#') continue;
            //if (dist[nh][nw] != -1) continue;
            if (c[nh][nw] == '.' && dist[nh][nw] == -1) {
                dist[nh][nw] = dist[h][w] + 1;
                Q.push(make_pair(nh, nw));
            }
        }
    }

    if (dist[H][W] != -1)
        cout << cnt - dist[H][W] << endl;
    else
        cout << -1 << endl;
}