#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
#define MOD 1000000007
using namespace std;
int n,k,a[105],dp[105][M];
int pre[M];
int mod(int x) { x %= MOD; if (x<0) x += MOD; return x; }

int main()
{
    scanf("%d %d", &n, &k);
    REP(i,1,n) scanf("%d", &a[i]);

    REP(i,0,a[1]) dp[1][i] = 1;
    REP(i,2,n) {
        pre[0] = dp[i-1][0];
        REP(j,1,k) pre[j] = mod(pre[j-1] + dp[i-1][j]);
        
        REP(j,0,k) {
            int r = j;
            int l = max(0, j-a[i]);
            int sum = pre[r];
            if (l>0) sum = mod(sum - pre[l-1]);
            dp[i][j] = sum;
        }
    }
    
    printf("%d\n", dp[n][k]);
    return 0;
}
