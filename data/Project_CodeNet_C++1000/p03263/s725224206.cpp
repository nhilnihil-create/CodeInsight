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

    int H, W;
    cin >> H >> W;
    vector<vector<int>> mat(H, vector<int>(W, 0));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> mat[i][j];
        }
    }

    // int total = 0;

    // for (int i = 0; i < H; ++i) {
    //     for (int j = 0; j < W; ++j) {
    //         total += mat[i][j];
    //     }
    // }


    vector<vector<int>> moves;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j + 1 < W; ++j) {
            if (mat[i][j] % 2) {
                moves.emplace_back(vector<int>{i, j, i, j + 1});
                mat[i][j] -= 1;
                mat[i][j + 1] += 1;
            }
        }
    }

    for (int i = 0; i + 1 < H; ++i) {
        if (mat[i][W - 1] % 2) {
            moves.emplace_back(vector<int>{i, W - 1, i + 1, W - 1});
            mat[i][W - 1] -= 1;
            mat[i + 1][W - 1] += 1;
        }
    }

    // {
    //     int cnt = 0;
    //     for (auto& V : mat) {
    //         for (auto x : V) {
    //             if (x % 2 == 0) {
    //                 ++cnt;
    //             }
    //         }
    //     }
    //     cout << cnt << '\n';
    // }

    cout << moves.size() << '\n';
    for (auto& M : moves) {
        cout << M[0] + 1 << ' ' << M[1] + 1 << ' ' << M[2] + 1 << ' ' << M[3] + 1  << '\n';
    }


    return 0;
}