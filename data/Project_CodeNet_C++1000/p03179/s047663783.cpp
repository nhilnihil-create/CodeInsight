#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

const int64_t MOD = 1e9 + 7;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int64_t>> dp(n, vector<int64_t>(n));
    vector<int64_t> dpsum(n + 1);
    rep(i, n)
    {
        if (i == 0) {
            rep(j, n)
            {
                dp[i][j] = j == 0 ? 1 : 0;
            }
        } else {
            rep(j, n)
            {
                if (j > i) {
                    dp[i][j] = 0;
                } else {
                    if (s[i - 1] == '>') {
                        dp[i][j] = (dpsum[i] - dpsum[j] + MOD) % MOD;
                    } else {
                        dp[i][j] = (dpsum[j] - dpsum[0] + MOD) % MOD;
                    }
                }
            }
        }
        dpsum[0] = 0;
        rep(j, n)
        {
            dpsum[j + 1] = (dpsum[j] + dp[i][j]) % MOD;
        }
    }
    cout << dpsum[n] << endl;

    return 0;
}