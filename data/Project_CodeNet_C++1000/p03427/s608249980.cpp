#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    // dp[digit][smaller]
    int dp[20][2] = {};
    dp[0][1] = -INF;

    rep(i, n) {
        int ni = i+1;
        int nd = s[i] - '0';
        rep(j, 2) {
            rep(d, 10) {
                int nj = j;

                if (j == 0) {
                    if (d < nd) nj = 1;
                    if (d > nd) continue;
                }

                dp[ni][nj] = max(dp[ni][nj], dp[i][j] + d);
            }
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}