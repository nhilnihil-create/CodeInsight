#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define reps(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; --i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repc2(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define inf 2e9
#define linf 9000000000000000000ll
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int n;
double p[3000];
double dp[3000][3000];  // dp[i][j] = i枚目までで表がj枚出る確率

int main() {
    cin >> n;
    reps(i, n) cin >> p[i];
    dp[0][0] = 1;
    reps(i, n) repc2(j, 0, n) {
        if (j == 0)
            dp[i][j] = dp[i - 1][j] * (1 - p[i]);
        else
            dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
    }
    double ans = 0;
    repc2(i, n / 2 + 1, n) ans += dp[n][i];
    cout << fixed << setprecision(10);
    cout << ans << endl;
    return 0;
}