#include<bits/stdc++.h>
using namespace std;
int dp[1 << 20][2];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); i++) {
        cin >> dp[i][0];
    }
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < (1 << n); i++) {
            if(i & (1 << j)) {
                int a = dp[i ^ (1 << j)][0], b = dp[i ^ (1 << j)][1];
                if(a >= dp[i][0]) {
                    dp[i][1] = max(dp[i][0], b);
                    dp[i][0] = a;
                }
                else {
                    dp[i][1] = max(dp[i][1], max(a, b));
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < (1 << n); i++) {
        ans = max(ans, dp[i][0] + dp[i][1]);
        cout << ans << endl;
    }
    return 0;
}