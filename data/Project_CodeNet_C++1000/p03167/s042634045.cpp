
// Problem: H - Grid 1
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_h
// Parsed on: 2020-09-07 11:16:54
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define md ((int)1e9 + 7)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> dp(h, vector<int>(w));
    vector<string> ar(h);
    for (auto &e : ar) cin >> e;

    dp[0][0] = 1;
    for (int a = 0; a < h; a++)
        for (int b = 0; b < w; b++) {
            if (a == b && a == 0) continue;
            if (ar[a][b] == '#')
                dp[a][b] = 0;
            else
                dp[a][b] = ((a ? dp[a - 1][b] : 0)%md + (b ? dp[a][b - 1] : 0)%md)%md;
        }

    cout << dp.back().back();

    return 0;
}
