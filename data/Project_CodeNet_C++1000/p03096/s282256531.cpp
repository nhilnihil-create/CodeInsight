#include <algorithm>
#include <cmath>
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
    cin >> n;
    vector<int> c(n);
    rep(i, n)
    {
        cin >> c[i];
        c[i]--;
    }
    c.erase(unique(c.begin(), c.end()), c.end());
    n = c.size();

    vector<int64_t> dp(n + 1);
    vector<int64_t> dp2(200'000, 0);
    irep(i, n)
    {
        if (i == 0) {
            dp[i] = 1;
        } else {
            dp2[c[i - 1]] += dp[i - 1];
            dp2[c[i - 1]] %= MOD;
            dp[i] = dp2[c[i - 1]];
        }
    }

    cout << dp[n] << endl;

    return 0;
}