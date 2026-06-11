#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, i, j;
    cin >> n >> k;
    int a[n];
    long dp[k+1] = {0}, m = 1000000007;
    for(i = 0; i < n; ++i) 
        cin >> a[i];
    for(j = 0; j <= a[0]; ++j) 
        dp[j] = 1;
    for(i = 1; i < n; ++i) {
        for(j = 0; j < k; ++j) 
            dp[j+1] = (dp[j] + dp[j+1]) % m;
        for(j = k; j >= 0; --j)
            if(j-a[i]-1 >= 0) 
                dp[j] = (dp[j] - dp[j-a[i]-1] + m) % m;
    }
    cout << dp[k] % m;
    return 0;
}