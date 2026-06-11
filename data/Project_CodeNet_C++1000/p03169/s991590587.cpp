#include <bits/stdc++.h>
#define dou long double

using namespace std;

const int MAXN = 3e2 + 10;
int a[MAXN];
dou dp[MAXN][MAXN][MAXN];

int main() {
    ios::sync_with_stdio(0), cin.tie();
    cout.tie(0);

    cout << setprecision(9) << fixed;

    int ii = 0, jj = 0, kk = 0;
    dou n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1)
            ii++;
        else if (a[i] == 2)
            jj++;
        else
            kk++;
    }

    for (int k = 0; k <= n; ++k)
        for (int j = 0; j <= n; ++j)
            for (int i = 0; i <= n; ++i) {
                dou X = 0;
                if (!i && !j && !k)
                    continue;
                if (i)
                    X += (i / n) * dp[i - 1][j][k];
                if (j)
                    X += (j / n) * dp[i + 1][j - 1][k];
                if (k) 
                    X += (k / n) * dp[i][j + 1][k - 1];
                dp[i][j][k] = (X + 1) * (n / (i + j + k));
            }

    cout << dp[ii][jj][kk] << '\n';

    // dp[i][j][k] = (i / n) * dp[i - 1][j][k] + (j / n) * dp[i + 1][j - 1][k] + (k / n) * dp[i][j + 1][k - 1] + ((n - i - j - k) / n) * dp[i][j][k]
    // (i / n) * dp[i - 1][j][k] + (j / n) * dp[i + 1][j - 1][k] + (k / n) * dp[i][j + 1][k - 1] = (((n - i - j - k) / n) - 1) * dp[i][j][k]
    
    // X = ((i / n) * dp[i - 1][j][k] + (j / n) * dp[i + 1][j - 1][k] + (k / n) * dp[i][j + 1][k - 1]))
    // dp[i][j][k] = -1 * X / (((n - i - j - k) / n) - 1)
    // dp[i][j][k] = X * (n / (i + j + k))
   
    return 0;
}
