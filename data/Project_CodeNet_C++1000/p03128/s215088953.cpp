#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    const vector<int> c{-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    vector<int> dp(n + 10, -1);
    dp[0] = 0;
    for (int d : a) {
        dp[c[d]] = 1;
    }

    for (int i = 0; i <= n; ++i) {
        for (int d : a) {
            if (i - c[d] >= 0 && dp[i - c[d]] != -1)
                dp[i] = max(dp[i], dp[i - c[d]] + 1);
        }
    }

    string ans = "";
    while (n > 0) {
        int max_digit = -1;
        int cand = -1;
        for (int d : a) {
            if (n - c[d] >= 0 && dp[n - c[d]] != -1) {
                if (dp[n - c[d]] > max_digit) {
                    cand = d;
                    max_digit = dp[n - c[d]];
                } else if (dp[n - c[d]] == max_digit && d > cand) {
                    cand = d;
                }
            }
        }
        n -= c[cand];
        ans += (char)(cand + '0');
    }

    cout << ans << endl;
    return 0;
}