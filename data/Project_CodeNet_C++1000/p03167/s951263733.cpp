#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 1005
#define MOD 1000000007
using namespace std;
int n,m,dp[M][M];
char in[M][M];
int main()
{
    scanf("%d %d", &n, &m);
    REP(i,1,n) scanf("%s", in[i] + 1);

    dp[1][1] = 1;
    REP(i,1,n)REP(j,1,m) if(in[i][j] != '#') {
        if (i==1 && j==1) continue;
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
        dp[i][j] %= MOD;
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
