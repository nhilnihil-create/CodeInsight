#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    vector<vector<int>> dist(H, vector<int>(W, 1e9));
    queue<pair<int, int>> q;
    for (int i = 0; i < H; i++) {
        cin >> A[i];
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                dist[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    int output = 0;
    while (!q.empty()) {
        int h = q.front().first;
        int w = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (h + dx[i] < 0 || h + dx[i] >= H || w + dy[i] < 0 ||
                w + dy[i] >= W)
                continue;
            if (dist[h + dx[i]][w + dy[i]] > dist[h][w] + 1) {
                dist[h + dx[i]][w + dy[i]] = dist[h][w] + 1;
                output = max(output, dist[h][w] + 1);
                q.emplace(h + dx[i], w + dy[i]);
            }
        }
    }

    cout << output << endl;

    return 0;
}
