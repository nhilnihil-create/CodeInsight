#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int N; 
    cin >> N;
    int abc[100010][3]{};
    for (int i = 0; i < N; ++i) for (int j = 0; j < 3; ++j) cin >> abc[i][j];
    int dp[100010][3]{};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + abc[i][k]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < 3; ++i) res = max(res, dp[N][i]);
    cout << res << endl;
    return 0;
}