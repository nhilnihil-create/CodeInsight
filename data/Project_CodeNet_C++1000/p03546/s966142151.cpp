#include <algorithm>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> c(10, vector<int>(10, 0));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c[i][j];
        }
    }

    vector<vector<int>> A(H, vector<int>(W));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> A[h][w];
        }
    }

    // dikstra
    // vector<int> dist(10, 1e9);
    // priority_queue<pair<int, int>, vector<pair<int, int>>,
    // greater<pair<int, int>>>
    // que;
    // que.emplace(0, 1);
    // dist[1] = 0;
    // while (!que.empty()) {
    // int index = que.top().second;
    // int cost = que.top().first;
    // que.pop();
    // if (dist[index] < cost) continue;
    // dist[index] = cost;
    // for (int i = 0; i < 10; i++) {
    // if (dist[i] == 1e9) {
    // que.emplace(cost + c[i][index], i);
    // }
    // }
    // }

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
    vector<int> dist(10);
    for (int i = 0; i < 10; i++) {
        dist[i] = c[i][1];
    }

    // for (int i = 0; i < 10; i++) {
    // cout << i << " " << dist[i] << endl;
    // }

    int output = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (A[h][w] != -1) {
                output += dist[A[h][w]];
            }
        }
    }
    cout << output << endl;

    return 0;
}
