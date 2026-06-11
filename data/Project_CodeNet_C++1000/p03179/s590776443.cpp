#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 3005
#define MOD 1000000007
using namespace std;
int n, dp[M][M], pre[M];
char in[M];
int main()
{
    scanf("%d%s",&n, in+1);
    
    REP(i,0,n-1) dp[1][i] = 1;
    REP(i,2,n) {
        MSET(pre, 0);
        pre[0] = dp[i-1][0];
        REP(j,1,n-1) pre[j] = (pre[j-1] + dp[i-1][j]) % MOD;

        REP(j,0,n-i) {
            if (in[i-1]=='<') {
                dp[i][j] = pre[j];
            } else {
                int tmp = pre[n-1];
                tmp = (tmp-pre[j])%MOD;
                if (tmp < 0) tmp += MOD;
                dp[i][j] = tmp;
            }
        }
    }
    
    printf("%d\n", dp[n][0]);
    return 0;
}
