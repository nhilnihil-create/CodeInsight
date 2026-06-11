#include <iostream>
#define nmax 5005
using std::cin;
using std::cout;
long long min(long long x, long long y)
{
    return (y < x) ? y : x;
}
int n, x[nmax+1], p[nmax+1];
long long dp[nmax+1][nmax*2+1], a, b;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b;
    for(int i = 1; i <= n; ++i)
      cin >> p[i];
    for(int i = 1; i <= n; ++i)
      x[p[i]] = (i << 1) - 1;
    for(int i = 1; i <= n; ++i){
      dp[i][0] = dp[i - 1][0] + b;
      for(int j = 1; j <= n << 1; ++j)
        dp[i][j] = min(dp[i][j - 1], ((j < x[i]) ? b : ((j > x[i]) ? a : 0)) + ((j & 1) ? dp[i - 1][j - 1] : dp[i - 1][j]));
    }
    cout << dp[n][n * 2];
    return 0;
}
