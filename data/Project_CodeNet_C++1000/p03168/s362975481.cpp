#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;  cin >> n;
    double *p = new double[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    vector<vector<double> > dp(n+1, vector<double>(n+1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i+1][j] += dp[i][j] * (1-p[i]);
            if (j > 0)
                dp[i+1][j] += dp[i][j-1] * p[i];
        }
    }

    double ans = 0;
    for (int i = n/2+1; i <= n; i++) {
        ans += dp[n][i];
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}