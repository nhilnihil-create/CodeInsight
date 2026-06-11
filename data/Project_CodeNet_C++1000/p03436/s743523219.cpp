#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int dist[51][51];

int main() {
    int H, W;
    int count = 0;
    cin >> H >> W;

    vector<string>S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            dist[i][j] = -1;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') {
                count++;
            }
        }
    }

    dist[0][0] = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));

    while (!que.empty()) {
        int h = que.front().first;
        int w = que.front().second;
        que.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nh = h + dx[dir];
            int nw = w + dy[dir];

            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (dist[nh][nw] != -1) continue;
            if (S[nh][nw] == '#') continue;
            dist[nh][nw] = dist[h][w] + 1;
            que.push(make_pair(nh, nw));
        }
    }
    if (dist[H-1][W-1] == -1) {
        cout << -1 << endl;
    } else {
        cout << count - dist[H-1][W-1] -1 << endl;
    }
}
