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
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000000LL;
constexpr int inf = 1000000000;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
    }

    if (n <= 2) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> idx(200001, -1);
    idx[c[0]] = 0;
    idx[c[1]] = 1;
    vector<ll> dp(n);
    dp[0] = dp[1] = 1;
    constexpr ll mod = 1000000007LL;
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (idx[c[i]] != -1 && idx[c[i]] + 2 <= i) {
            dp[i] += dp[idx[c[i]]];
            dp[i] %= mod;
        }

        idx[c[i]] = i;
    }

    cout << dp.back() << endl;

    return 0;
}