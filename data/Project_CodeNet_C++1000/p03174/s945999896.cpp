#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 22
#define MOD 1000000007
#define B(x) (1<<(x))
using namespace std;
int n,dp[M][1<<M];
int a[M][M];
int main()
{
    scanf("%d", &n);
    REP(i,1,n) REP(j,1,n) scanf("%d", &a[i][j]);

    dp[0][0] = 1;
    REP(i,1,n) REP(j,0,B(n)-1) if (__builtin_popcount(j) == i) {
        REP(k,1,n) if(a[i][k] && (B(k-1)&j)) {
            int i2 = i-1;
            int j2 = j ^ B(k-1);
            dp[i][j] += dp[i2][j2];
            dp[i][j] %= MOD;
        }
    }
    printf("%d\n", dp[n][B(n)-1]);

    return 0;
}
