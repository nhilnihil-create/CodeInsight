#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < n; i++)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n;
    cin >> n;
    int dp[n + 1];
    rep (i, n + 1) dp[i] = i;
    //配るDP
    /*rep (i, n + 1) {
        for (int j = 1; i + j <= n; j *= 6) {
            dp[i + j] = min (dp[i + j], dp[i] + 1);
        }
        for (int j = 1; i + j <= n; j *= 9) {
            dp[i + j] = min (dp[i + j], dp[i] + 1);
        }
    }*/
    //貰うDP
    rep (j, n + 1) {
        for (int i = 1; i <= j; i *= 6) {
            dp[j] = min (dp[j], dp[j - i] + 1);
        }
        for (int i = 1; i <= j; i *= 9) {
            dp[j] = min (dp[j], dp[j - i] + 1);
        }
    }
    cout << dp[n] << "\n";
}