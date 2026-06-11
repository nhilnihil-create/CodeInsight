#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9+7;
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n,vector<int>(n,0));
    for(int i =0;i<n;i++)
        for(int j = 0;j<n;j++)
        {
            cin >> grid[i][j];
        }
    
    vector<long long > dp(1<<n);
    dp[0] = 1;
    for(int mask = 0;mask < (1 << n) -1; mask++)
    {
        int  a = __builtin_popcount(mask);
        for(int b = 0;b < n;b++)
        {
            if(grid[a][b] && !(mask & (1 << b)))
            {
                int m = mask | (1 << b);
                dp[m] += (dp[mask]%MOD);
            }
        }
    }
    
    cout << dp[(1<<n)-1]%MOD << endl;
    return 0;
}