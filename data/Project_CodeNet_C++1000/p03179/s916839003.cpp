#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iterator>
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
#include <cctype>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)

const int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<vector<int>>dp(n + 13, vector<int>(n + 13, 0));
    dp[1][0] = 1;
    for (int i = 2; i <= n; i++) {
        vector<int> sum(i);
        for (int j = 0; j < i - 1; j++) {
            sum[j + 1] = (sum[j] + dp[i - 1][j]) % mod;
        }
        for (int j = 0; j < i; j++) {
            if (s[i - 2] == '<') {
                dp[i][j] = sum[j];
            } else {
                dp[i][j] = (sum.back() - sum[j] + mod) % mod;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
        ans += dp[n][j];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
