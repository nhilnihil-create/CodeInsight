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

    int n, K;
    cin >> n >> K;
    vector<vector<long long>> X(n, vector<long long>(3, 0));
    for (int i = 0; i < n; ++i) {
        cin >> X[i][0] >> X[i][1] >> X[i][2];
    }

    int m = 3;
    int M = 1 << m;

    const long long INF = 1LL << 60;
    vector<vector<long long>> dp(K + 1,  vector<long long>(M, -INF));
    for (int i = 0; i < M; ++i) {
        dp[0][i] = 0;
    }


    long long res = -INF;
    for (int i = 0; i < n; ++i) {
 
        for (int k = K - 1; k >= 0; --k) {
            for (int j = 0; j < M; ++j) {
                if (dp[k][j] <= -INF) {
                    continue;
                }

                long long ans = dp[k][j];
                for (int s = 0; s < 3; ++s) {
                    if (j & (1 << s)) {
                        ans += X[i][s];
                    } else {
                        ans -= X[i][s];
                    }
                }
                dp[k + 1][j] = max(dp[k + 1][j], ans);
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        res = max(res, dp[K][i]);
    }
    cout << res  << '\n';

    return 0;
}