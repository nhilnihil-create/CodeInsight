#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int ways(int mask, int woman, int n, vector<vector<int> > &match, vector<vector<int> > &dp) {
    if (woman == n)
        return 1;
    if (dp[woman][mask] != -1)
        return dp[woman][mask];
    int currWays = 0;
    for (int man = 0; man < n; man++) {
        if ((mask & (1<<man)) && match[man][woman]) {
            currWays = (currWays % mod + ways(mask ^ (1<<man), woman+1, n, match, dp) % mod ) % mod;
        }
    }
    return dp[woman][mask] = currWays;
}
int main() {
    int n;
    cin>>n;
    vector<vector<int> > match(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin>>match[i][j];
    }
    vector<vector<int> > dp(n, vector<int> (1<<n, -1));
    cout<<ways((1<<n)-1, 0, n, match, dp)<<"\n";
    return 0;
}
