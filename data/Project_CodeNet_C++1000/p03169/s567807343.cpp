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
double dp[301][301][301];
int c[3];

double rec(int i, int j, int k) {
    if (dp[i][j][k] > -0.5)
        return dp[i][j][k];
    double d = 1. - (double)(n - i - j - k) / n;
    dp[i][j][k] = 1. / d;
    if (i > 0)
        dp[i][j][k] += rec(i - 1, j, k) * (double)(i) / n / d;
    if (j > 0)
        dp[i][j][k] += rec(i + 1, j - 1, k) * (double)(j) / n / d;
    if (k > 0)
        dp[i][j][k] += rec(i, j + 1, k - 1) * (double)(k) / n / d;
    return dp[i][j][k];
}

int main() {
    cin >> n;
    rep(i, n) {
        int m;
        cin >> m;
        c[m - 1]++;
    }
    rep(i, 301) rep(j, 301) rep(k, 301) dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    cout << fixed << setprecision(10);
    cout << rec(c[0], c[1], c[2]) << endl;
    return 0;
}