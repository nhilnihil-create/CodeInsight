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

    int n, C;
    cin >> n >> C;

    vector<vector<int>> D(C, vector<int>(C, 0));
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> D[i][j];
        }
    }

    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
            --M[i][j];
        }
    }

    vector<vector<int>> cnts(3, vector<int>(C, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cnts[(i + j) % 3][M[i][j]] += 1;
        }
    }

    const long long INF = 1LL << 50;
    vector<vector<long long>> dp(3, vector<long long>(C, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < C; ++j) {
            for (int k = 0; k < C; ++k) {
                dp[i][j] += cnts[i][k] * 1LL * D[k][j];
            }
        }
    }

    long long res = INF;
    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < C; ++j) {
            for (int k = 0; k < C; ++k) {
                if (i != j && i != k && j != k) {
                    long long ans = dp[0][i] + dp[1][j] + dp[2][k];
                    res = min(res, ans);
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}