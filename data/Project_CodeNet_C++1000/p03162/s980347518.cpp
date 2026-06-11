#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000007;
const long long INF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll abc[100100][3]{};
ll dp[100100][3]{};

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; ++i) for (int j = 0; j < 3; ++j) cin >> abc[i][j];
    for (int a = 0; a < N; ++a) {
        for (int b = 0; b < 3; ++b) {
            for (int c = 0; c < 3; ++c) {
                if (b == c) continue;
                chmax(dp[a+1][c], dp[a][b] + abc[a][c]);
            }
        }
    }
    ll res = 0;
    for (int i = 0; i < 3; ++i) chmax(res, dp[N][i]);
    cout << res << endl;
    return 0;
}