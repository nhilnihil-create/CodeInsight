#include<bits/stdc++.h>
using namespace std;
long long Max = LONG_MAX;
int n, ar[100050] = {};
long long dp[100005] = {};
void findSolution(int pos, int pre)
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
    if(pos+1 <= n)
    {
        findSolution(pos+1, pos);
    }
    if(pos+2 <= n)
    {
        findSolution(pos+2, pos);
    }
    dp[pre] = min(dp[pre], abs(ar[pre]-ar[pos])+dp[pos]);
}
void solve()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &ar[i]);
    }
    for(int i = 0; i <= n+2; i++)
    {
        dp[i] = Max;
    }
    dp[n] = 0;
    findSolution(1, 0);
    cout << dp[1] << endl;
}
int main()
{
    solve();
    return 0;
}