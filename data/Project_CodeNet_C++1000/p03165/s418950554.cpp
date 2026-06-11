#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(),x.end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9+7;
const ll INF = 1e18;
const int MAX = 1e6;

// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

struct edge {int to, cost;}; // 辺
// vector<edge> graph[MAX]; // 隣接リスト
// bool visit[MAX]; // 訪問の有無

int n, m; // 変数
string s, t;
int dp[3001][3001];
string ans;

void lcs(int i, int j) { // LCSの復元
    if (i == 0 || j == 0) return;
    if (s[i] == t[j]) {
        ans.push_back(s[i]);
        lcs(i-1, j-1);
    } else if (dp[i][j] == dp[i-1][j]) {
        lcs(i-1, j);
    } else if (dp[i][j] == dp[i][j-1]) {
        lcs(i, j-1);
    }
}

int rec(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == 0 || j == 0) return dp[i][j] = 0;
    if (s[i] == t[j]) return dp[i][j] = rec(i-1, j-1) + 1;
    int x = rec(i-1, j);
    int y = rec(i, j-1);
    return dp[i][j] = max(x, y);
}

int main() {
// input
    cin >> s;
    cin >> t;
// solve
    s = ' ' + s;
    t = ' ' + t;
    n = s.size();
    m = t.size();
    rep(i, n) {
        rep(j, m) {
            dp[i][j] = -1;
        }
    }
    rec(n-1, m-1);
    lcs(n-1, m-1);
    reverse(ALL(ans));
// output
    cout << ans << "\n";
}