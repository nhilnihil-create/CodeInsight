#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define mod 1000000007
int dp[2097152][21];
int mat[21][21];
int solve(int msk, int i, int n)
{
    if(i == n)
        return 1;
    if(dp[msk][i] != -1)
        return dp[msk][i];
    int ans = 0;
    for(int j = 0;j < n;j++)
    {
        if(mat[i][j] == 1)
        {
            if(msk&(1 << j))
                continue;
            ans = (ans + solve((msk|(1 << j)), i+1, n))%mod;
        }
    }
    return (dp[msk][i] = ans);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin >> mat[i][j];
    for(i=0;i<2097152;i++)
        for(j=0;j<21;j++)
            dp[i][j] = -1;
    cout << solve(0, 0, n);
}