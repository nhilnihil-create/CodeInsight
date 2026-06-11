#include <iostream>
#include <iomanip>
using namespace std;

int n;
long double p, ans, dp[3005][2];

int main() {
    cin >> n;
    dp[0][1] = 1;
    for (int i = 0; i < n; i++){
        cin >> p;
        dp[0][i&1] = 0;
        for (int j = 0; j <= i; j++){
            dp[j+1][i&1] = dp[j][(i&1)^1] * p;
            dp[j][i&1] += dp[j][(i&1)^1] * (1.0-p);
        }
    }
    for (int i = n; i > n/2; i--){
        ans += dp[i][0];
    }
    cout << fixed << setprecision(15) << ans << "\n";
}
