#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
#define MOD 1000000007
using namespace std;
using LL = long long;
int n;
LL dp[M][2];
vector<int> e[M];
void dfs(int cur,int fa) {
    dp[cur][0] = dp[cur][1] = 1;
    for (int i: e[cur]) if (i!=fa) {
        dfs(i, cur);
        dp[cur][0] *= (dp[i][0] + dp[i][1]);
        dp[cur][0] %= MOD;
        dp[cur][1] = (dp[cur][1] * dp[i][0]) % MOD;
    }
}
int main()
{
    scanf("%d", &n);
    REP(i,1,n-1) {
        int x, y;
        scanf("%d %d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }

    dfs(1, -1);
    printf("%lld\n", (dp[1][0] + dp[1][1]) % MOD);
    return 0;
}
