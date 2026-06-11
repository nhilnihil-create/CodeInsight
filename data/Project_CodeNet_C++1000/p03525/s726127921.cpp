//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

template <typename T>
vector<vector<T>> alloc_2d_vec(size_t rows, size_t cols, T init)
{
    vector<vector<T>> ret;
    vector<T> ret_elem;
    ret_elem.resize(cols, init);
    ret.resize(rows, ret_elem);
    return ret;
}

template <typename T>
vector<vector<vector<T>>> alloc_3d_vec(size_t x, size_t y, size_t z, T init) {
    vector<vector<vector<T>>> ret;
    vector<vector<T>> ret_elem = alloc_2d_vec(y, z, init);
    ret.resize(x, ret_elem);
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<int> dis;
    for (int i = 0; i < N; i++) {
        int di;
        cin >> di;
        dis.push_back(di);
    }
    sort(dis.begin(), dis.end());
    int k = 0;
    while (true) {
        k++;
        vector<vector<vector<bool>>> dp = alloc_3d_vec(dis.size()+1, 12+1, 12+1, false);
        dp[0][0][0] = true;
        for (int i = 1; i <= dis.size(); i++) {
            for (int left = 0; left <= 12; left++) {
                for (int right = 0; right <= 12; right++) {
                    int di = dis[i-1];
                    if (right == di) {
                        if (24 - right - left < k) {
                            dp[i][left][right] = false;
                        } else {
                            bool found = false;
                            for (int before_right = right - k; before_right >= 0; before_right--) {
                                if (dp[i-1][left][before_right]) {
                                    found = true;
                                    break;
                                }
                            }
                            dp[i][left][right] = found;
                        }
                    } else if (left == di) {
                        if (24 - left - right < k) {
                            dp[i][left][right] = false;
                        } else {
                            bool found = false;
                            for (int before_left = left - k; before_left >= 0; before_left--) {
                                if (dp[i-1][before_left][right]) {
                                    found = true;
                                    break;
                                }
                            }
                            dp[i][left][right] = found;
                        }
                    } else {
                        dp[i][left][right] = false;
                    }
                }
            }
        }
        bool found = false;
        for (int l = 0; l <= 12; l++) {
            for (int r = 0; r <= 12; r++) {
                if (dp[dis.size()][l][r]) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            k--;
            break;
        }
    }
    cout << k << endl;
}
