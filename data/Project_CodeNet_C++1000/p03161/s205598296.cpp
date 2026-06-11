#include<bits/stdc++.h>
using namespace std;
long long Max = LONG_MAX;
int n, ar[100050] = {};
long long dp[100005] = {};
void findSolution(int pos, int pre, int k)
{
    if(dp[pos] != Max)
    {
        long long d = abs(ar[pre]-ar[pos]);
        d += dp[pos];
        dp[pre] = min(dp[pre], d);
        return;
    }
    if(pos == n)
    {
        long long d = abs(ar[pos]-ar[pre]);
        d += dp[pos];
        dp[pre] = min(dp[pre], d);
        return;
    }
    for(int i = 1; i <= k; i++)
    {
        if(pos+i <= n)
        {
            findSolution(pos+i, pos, k);
        }
    }
    dp[pre] = min(dp[pre], abs(ar[pre]-ar[pos])+dp[pos]);
}
void solve()
{
    scanf("%d", &n); int k; scanf("%d", &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &ar[i]);
    }
    for(int i = 0; i <= n+2; i++)
    {
        dp[i] = Max;
    }
    dp[n] = 0;
    findSolution(1, 0, k);
    cout << dp[1] << endl;
}
int main()
{
    solve();
    return 0;
}