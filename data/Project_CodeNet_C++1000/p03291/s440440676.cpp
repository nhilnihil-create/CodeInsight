#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = (int) 1e5 + 10;
const int MOD = (int) 1e9 + 7;

ll dp[Maxn][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = (int) s.size();
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (s[i] == '?') {
                (dp[i + 1][j] += 3 * dp[i][j]) %= MOD;
            } else {
                (dp[i + 1][j] += dp[i][j]) %= MOD;
            }
        }
        if (s[i] == 'A' || s[i] == '?') {
            (dp[i + 1][1] += dp[i][0]) %= MOD;
        }
        if (s[i] == 'B' || s[i] == '?') {
            (dp[i + 1][2] += dp[i][1]) %= MOD;
        }
        if (s[i] == 'C' || s[i] == '?') {
            (dp[i + 1][3] += dp[i][2]) %= MOD;
        }
    }

    cout << dp[n][3] << endl;
}
