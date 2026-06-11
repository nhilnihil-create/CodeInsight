#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MAXN 3000
double dp[MAXN][MAXN]; //何枚投げて何枚表か
double p[MAXN];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    dp[1][1] = p[1];
    dp[1][0] = 1 - p[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - p[i]);
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
        }
    }
    int m = n / 2;
    double x = 0;;
    for (int i = m + 1; i <= n; i++) {
        x += dp[n][i];
    }
    cout << setprecision(10) << x << endl;
    return 0;
}