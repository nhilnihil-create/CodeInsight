#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, i, j;
    cin >> n >> k;
    int dp[k+1], a[n];
    for(i = 0; i <= k; ++i) dp[i] = 1;
    for(i = 0; i < n; ++i) cin >> a[i];
    for(i = 1; i <= k; ++i)
        for(j = 0; j < n; ++j)
            if(a[j] <= i && dp[i-a[j]] == 1) {
                dp[i] = 0;
                break;
            }
    cout << (dp[k] ? "Second" : "First");
    return 0;
}