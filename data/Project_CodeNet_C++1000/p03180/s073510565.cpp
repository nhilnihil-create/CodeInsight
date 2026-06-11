#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 17
#define B(x) (1<<(x))
using namespace std;
using LL = long long;
int n,a[M][M];
LL sum[1<<M], dp[1<<M];
bool vis[1<<M];

LL dfs(int x) {
    if (x==0) return 0;
    if (vis[x]) return dp[x];
    vis[x] = true;
    LL &res = dp[x];
    res = sum[x];

    for (int i=(x-1)&x; i>0; i=(i-1)&x)
        res = max(res, dfs(i) + dfs(x^i));
    return res;
}
int main()
{
    scanf("%d", &n);
    REP(i,1,n) REP(j,1,n) scanf("%d", &a[i][j]);

    sum[0] = 0;
    REP(i,1,B(n)-1) {
        int low = __lg(i & -i) + 1;
        int j = i ^ B(low-1);
        sum[i] = sum[j];
        REP(k,1,n) if (k!=low && (B(k-1) & i)) sum[i] += a[low][k];
    }

    printf("%lld\n", dfs(B(n)-1));
    return 0;
}
