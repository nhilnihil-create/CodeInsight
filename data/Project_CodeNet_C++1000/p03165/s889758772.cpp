// Problem: F - LCS
// Contest: AtCoder - Educational DP Contest
// URL: https://atcoder.jp/contests/dp/tasks/dp_f
// Parsed on: 2020-09-06 16:58:46
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

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<vector<int>> dp(a.size(), vector<int>(b.size()));

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            if (a[i] == b[j]) {
                if (i && j)
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 1;
            } else
                dp[i][j] = max(i ? dp[i - 1][j] : 0, j ? dp[i][j - 1] : 0);

    int lcs = dp.back().back();
    string ans;
    int i, j;
    i = a.size() - 1;
    j = b.size() - 1;
    while (lcs != ans.size()) {
        if (a[i] == b[j]) {
            ans += a[i];
            i--;
            j--;
        } else {
            bool leftExists = i - 1 >= 0;
            bool topExists = j - 1 >= 0;

            if (leftExists ^ topExists) {
                if (leftExists)
                    i = i - 1;
                else
                    j = j - 1;
            } else {
                if (leftExists && topExists) {
                    if (dp[i - 1][j] > dp[i][j - 1])
                        i = i - 1;
                    else
                        j = j - 1;
                } else
                    break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}