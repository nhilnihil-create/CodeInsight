#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(),x.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;

const int mod = 1e9+7;
const ll INF = 1e18;
const int MAX = 1e6;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visit[MAX]; // 訪問状況

int n;
double p[3000];
double dp[3000][3000];

int main() {
// input
    cin >> n;
    rep(i, n) {
        cin >> p[i];
    }
// solve
    dp[0][0] = 1.0;

    // DP ループ
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i+1][j+1] += dp[i][j] * p[i];
            dp[i+1][j] += dp[i][j] * (1.0 - p[i]);
        }
    }
// output
    double ans = 0;
    for (int i = n; i > n/2; i--) {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(10) << ans << endl;
}