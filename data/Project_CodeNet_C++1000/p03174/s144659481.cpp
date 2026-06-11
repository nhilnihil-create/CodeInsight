#include <bits/stdc++.h>

using namespace std;
int mat[25][25];
int dp[(1 << 21) + 5];
int solve(int msk, int n)
{
    if(msk == (1 << n) - 1)
        return 1;
    
    if(dp[msk] != -1)
        return dp[msk];
    int a = __builtin_popcount(msk);
    int j, ans = 0;
    for(j=0;j<n;j++)
    {
        if(((msk >> j)&1) == 0 && mat[a][j] == 1)
        {
            //cout << i << " " << j << '\n';
           ans = (ans + solve(msk|(1 << j), n))%(1000000007); 
        }
    }
    return (dp[msk] = ans);
}
int main() {
    int n;
    cin >> n;
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin >> mat[i][j];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, n) << '\n';
}