#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
    int n;
    cin>>n;
    vector<vector<int> > match(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin>>match[i][j];
    }
    vector<int> dp(1<<n, 0);
    dp[0] = 1;
    for (int mask = 0; mask < (1<<n) - 1; mask++) {
        int man = __builtin_popcount(mask);
        for (int woman = 0; woman < n; woman++) {
            if (match[man][woman] && !(mask & (1<<woman))) {
                int nextMask = mask ^ (1<<woman);
                dp[nextMask] = (dp[nextMask] + dp[mask]) % mod;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
    return 0;
}
