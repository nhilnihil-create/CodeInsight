#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

char G[50][50];
int dst[50][50];

int main() {
    int H, W;
    cin >> H >> W;
    int num_white = 0;
    rep(i, H) {
        rep(j, W) {
            cin >> G[i][j];
            dst[i][j] = -1;
            if(G[i][j] == '.')
                num_white++;
        }
    }
    if(G[0][0] == '.')
        num_white--;

    vector<pair<int, int>> move = {{1, 0}, {0, 1} ,{-1, 0}, {0, -1}};

    queue<pair<int, int>> q;
    q.push({0, 0});
    dst[0][0] = 0;
    while(!q.empty()) {
        auto i = q.front().first;
        auto j = q.front().second;
        q.pop();
        for(auto m: move) {
            auto next_i = i + m.first;
            auto next_j = j + m.second;
            if(next_i < 0 || next_i >= H || next_j < 0 || next_j >= W) {
                continue;
            }
            if(G[next_i][next_j] != '.') {
                continue;
            }
            if(dst[next_i][next_j] >= 0)
                continue;
            dst[next_i][next_j] = dst[i][j]+1;
            if(next_i == H-1 && next_j == W-1)
                break;
            q.push({next_i, next_j});
        }
    }
#if 0
    rep(i, H) {
        rep(j, W) {
            printf("%02d ", dst[i][j]);
        }
        printf("\n");
    }
#endif

    if(dst[H-1][W-1] >= 0) {
//        cout << dst[H-1][W-1] << " " << num_white << " " << num_white - dst[H-1][W-1] << endl;
        cout << num_white - dst[H-1][W-1] << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

