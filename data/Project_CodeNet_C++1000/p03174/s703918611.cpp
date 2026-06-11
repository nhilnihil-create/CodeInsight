#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int board[25] [25], n;
long long dp[21] [1 << 21];
long long DP(int at, int mask){
    if(at == n)
        return 1;
    long long& k = dp[at] [mask];
    if(k != -1)
        return k;
    k = 0;
    for(int i = 0; i < n; i++)
        if(board[at] [i] == 1 && !(mask & (1 << i)))
            k =(k % mod + DP(at + 1, mask | (1 << i)) % mod) % mod;
    return k;
}
int main( ){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i] [j];
    memset(dp, -1, sizeof dp);
    long long ans = DP(0, 0);
    cout << ans << '\n';
    return 0;
}