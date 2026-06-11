#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> M(h);
    for (int i = 0; i < h; ++i) {
        cin >> M[i];
    }

    const int INF = 1 << 28;
    vector<vector<int>> dis(h, vector<int>(w, INF));
    dis[0][0] = 1;
    vector<pair<int,int>> que;
    que.emplace_back(0, 0);

    vector<int> X{-1, 1, 0, 0};
    vector<int> Y{0, 0, -1, 1};
    for (int i = 0; i < que.size(); ++i) {
        int x = que[i].first, y = que[i].second;
        for (int j = 0; j < X.size(); ++j) {
            int nx = x + X[j], ny = y + Y[j];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && M[nx][ny] == '.') {
                if (dis[nx][ny] > dis[x][y] + 1) {
                    dis[nx][ny] = dis[x][y] + 1;
                    que.emplace_back(nx, ny);
                }
            }
        }
    }

    int whites = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (M[i][j] == '.') {
                ++whites;
            }
        }
    }
    if (dis[h - 1][w - 1] >= INF) {
        cout << -1 << '\n';
    } else {
        // cout << whites << " " << dis[h - 1][w - 1] << endl;
        int res = whites - dis[h - 1][w - 1];
        cout << res << '\n';
    }


    return 0;
}