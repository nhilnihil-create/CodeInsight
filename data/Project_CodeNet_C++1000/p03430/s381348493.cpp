#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

string str;
int k;
int dp[300][301][301];

int main() {
    cin >> str;
    cin >> k;
    int n = str.size();
    int ans = 1;
    rep(i,n) dp[i][1][0] = 1;
    for (int j = 2; j <= n; j++) {
        rep(i,n-j+1) {
            for (int u = 0; u <= k; u++) {
                if (str[i] == str[i+j-1]) {
                    dp[i][j][u] = dp[i+1][j-2][u]+2;
                } else {
                    dp[i][j][u] = max(dp[i][j-1][u], dp[i+1][j-1][u]);
                }
                if (u >= 1) dp[i][j][u] = max(dp[i][j][u], dp[i+1][j-2][u-1]+2);
                ans = max(ans, dp[i][j][u]);
            }
        }
    }
    cout << ans << endl;
}






























