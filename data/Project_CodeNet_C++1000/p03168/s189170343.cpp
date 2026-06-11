#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 3005
using namespace std;
int n;
double p[M];
unordered_map<int, double> dp[M];
int main()
{
    scanf("%d", &n);
    REP(i,1,n) scanf("%lf", &p[i]);

    dp[1][1] = p[1];
    dp[1][-1] = 1.0 - p[1];
    REP(i,1,n-1) for (auto it:dp[i]) {
        int j = it.first;
        dp[i+1][j+1] += dp[i][j] * p[i+1];
        dp[i+1][j-1] += dp[i][j] * (1.0 - p[i+1]);
    }

    double ans = 0.0;
    for (auto it: dp[n]) if (it.first>=1) ans += dp[n][it.first];
    printf("%.10f\n", ans);
    return 0;
}
