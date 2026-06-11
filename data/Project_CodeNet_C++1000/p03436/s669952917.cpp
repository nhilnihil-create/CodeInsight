#include "bits/stdc++.h"

using namespace std;

void Main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int> > grids(H, vector<int>(W, 0));
    int origBlack = 0;
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < W; ++j) {
            if (s[j] == '#') {
                grids[i][j] = 1;
                ++origBlack;
            }
            else {
                grids[i][j] = 0;
            }
        }
    }

    vector<vector<int> > arrived(H, vector<int>(W, -1));
    queue<pair<int, int> > que;
    que.push(make_pair(0, 0));
    arrived[0][0] = 0;
    while (!que.empty()) {
        auto p = que.front();
        que.pop();
        int i = p.first;
        int j = p.second;
        int minStep = arrived[i][j];
        if (i < H - 1 && grids[i + 1][j] == 0 && arrived[i + 1][j] < 0) {
            arrived[i + 1][j] = minStep + 1;
            que.push(make_pair(i + 1, j));
        }
        if (0 < i && grids[i - 1][j] == 0 && arrived[i - 1][j] < 0) {
            arrived[i - 1][j] = minStep + 1;
            que.push(make_pair(i - 1, j));
        }
        if (j < W - 1 && grids[i][j + 1] == 0 && arrived[i][j + 1] < 0) {
            arrived[i][j + 1] = minStep + 1;
            que.push(make_pair(i, j + 1));
        }
        if (0 < j && grids[i][j - 1] == 0 && arrived[i][j - 1] < 0) {
            arrived[i][j - 1] = minStep + 1;
            que.push(make_pair(i, j - 1));
        }
    }

    int minStepPath = arrived[H - 1][W - 1];
    if (minStepPath == -1) {
        cout << -1 << endl;
        return;
    }
    cout << (H * W - 1 - minStepPath - origBlack) << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
