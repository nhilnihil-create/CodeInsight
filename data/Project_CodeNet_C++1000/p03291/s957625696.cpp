#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MOD = (int)1e9 + 7;
template<class T> void add(T &a, T b) { (a += (b % MOD + MOD) % MOD) %= MOD; }

int main() {
    string s; cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(4));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i] == 'A' || s[i] == '?') add(dp[i + 1][j], dp[i][j]);
            if (s[i] == 'B' || s[i] == '?') add(dp[i + 1][j], dp[i][j]);
            if (s[i] == 'C' || s[i] == '?') add(dp[i + 1][j], dp[i][j]);
        }
        {
            if (s[i] == 'A' || s[i] == '?') add(dp[i + 1][1], dp[i][0]);
            if (s[i] == 'B' || s[i] == '?') add(dp[i + 1][2], dp[i][1]);
            if (s[i] == 'C' || s[i] == '?') add(dp[i + 1][3], dp[i][2]);
        }
    }
    cout << dp[n][3] << endl;
    return 0;
}
