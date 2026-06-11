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

void dp_solve() {
    if (s.size() < t.size()) swap(s, t);
    s = ' ' + s;
    t = ' ' + t;
    n = s.size();
    m = t.size();
    rep(i, n) {
        rep(j, m) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            } else {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    int x = dp[i-1][j];
                    int y = dp[i][j-1];
                    dp[i][j] = max(x, y);
                }
            }
            // printf("%d ", dp[i][j]);
        }
        // printf("\n");
    }
    int i = n-1, j = m-1;
    while (i-1 >= 0 && j-1 >= 0) { 
        if (s[i] == t[j]) {
            ans.push_back(s[i]);
            i--;
            j--;
        } else if (dp[i][j] == dp[i-1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j-1]) {
            j--;
        }
    }
    reverse(ALL(ans));
}

int main() {
// input
    cin >> s;
    cin >> t;
// solve
    dp_solve();
// output
    cout << ans << "\n";
}