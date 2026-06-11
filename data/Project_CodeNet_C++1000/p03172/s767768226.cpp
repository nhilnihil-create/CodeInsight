#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
const int MOD = 1e9 + 7;
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
 
    vector<vll> dp(n+1, vector<ll> (k+1, 0));
    dp[0][0] = 1;
    /*
    dp[i][j] No of ways i candies be distributed among first j children so far.
    */
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        vll fake(k+1, 0);
        fake[0] = 1;
        for (int j = 1; j <= k; ++j) {
            fake[j] = (fake[j-1] + dp[i-1][j]) % MOD;
        }
        for (int j = 1; j <= k; ++j) {
            int l = max(j-a[i-1], 0);
            int r = j;
            if (l > 0) {
                dp[i][j] = (MOD+fake[r] - fake[l-1])%MOD;
            } else {
                dp[i][j] = fake[r];
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}