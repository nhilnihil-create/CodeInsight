#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int dp[n];
  dp[0]=0;
    for ( int i = 1 ; i < n + 1 ; i ++){
        dp[i] = dp[i - 1] + 1;
    }

    for (int six = 1; six <= n; six *= 6) {
        for (int j = 1; j < n + 1; j++) {
            if (j - six < 0) {
                continue;
            }
            dp[j] = min(dp[j - six] + 1, dp[j]);
        }
    }

    for (int nine = 1; nine < n + 1; nine *= 9) {
            for (int j = 1; j < n + 1; j++) {
                if (j - nine < 0) {
                    continue;
                }
                dp[j] = min(dp[j - nine] + 1, dp[j]);
            }
        }
    cout << dp[n] << endl;
}