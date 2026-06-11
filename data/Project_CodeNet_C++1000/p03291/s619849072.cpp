#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll dp[200010][5];

int main(){
    string s;
    cin >> s;
    int n = s.size();
    dp[0][0] = 1;
    rep(i, n){
        rep(j, 5) {
            if (s[i] != '?') dp[i+1][j] += dp[i][j];
            else dp[i+1][j] += dp[i][j] * 3;
            dp[i+1][j] %= MOD;
        }
        if (s[i] == 'A' || s[i] == '?') dp[i+1][1] += dp[i][0];
        if (s[i] == 'B' || s[i] == '?') dp[i+1][2] += dp[i][1];
        if (s[i] == 'C' || s[i] == '?') dp[i+1][3] += dp[i][2];
        dp[i+1][1] %= MOD, dp[i+1][2] %= MOD, dp[i+1][3] %= MOD;
    }
    cout << dp[n][3] << endl;
    return 0;
}
