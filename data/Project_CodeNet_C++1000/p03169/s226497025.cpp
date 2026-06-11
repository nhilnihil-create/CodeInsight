#include <bits/stdc++.h>

using namespace std;
#define int long long
using ld = long double;
ld dp[301][301][301];
ld solve(int a, int b, int c, int n)
{
    if(a < 0 || b < 0 || c < 0 || a > n || b > n || c > n)
        return 0;
    if(dp[a][b][c] != -1)
        return dp[a][b][c];
    ld x = solve(a-1, b, c, n);
    ld y = solve(a+1, b-1, c, n);
    ld z = solve(a, b+1, c-1, n);
    ld ans = (x*a + y*b + z*c + n);
    ans = ans/(a+b+c);
    return (dp[a][b][c] = ans);
}
signed main() {
    int cnt[4] = {0};
    int n;
    cin >> n;
    int i, j, k;
    for(i=1;i<=n;i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(i=0;i<=300;i++)
        for(j=0;j<=300;j++)
            for(k=0;k<=300;k++)
                dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    cout << fixed << setprecision(10) << solve(cnt[1], cnt[2], cnt[3], n);
    // dp[n][0][0]
}