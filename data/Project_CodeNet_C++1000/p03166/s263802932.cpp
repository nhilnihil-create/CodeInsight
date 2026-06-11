#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,m,dp[M];
bool vis[M];
vector<int> e[M];
int dfs(int cur) {
    if (vis[cur]) {
        return dp[cur];
    }

    int &res = dp[cur];
    for (int i:e[cur]) res = max(res, 1+dfs(i));
    vis[cur] = true;
    return res;
}
int main()
{
    scanf("%d %d", &n, &m);
    REP(i,1,m) {
        int x,y;
        scanf("%d %d", &x, &y);
        e[x].push_back(y);
    }

    int ans = 0;
    REP(i,1,n) ans = max(ans, dfs(i));
    printf("%d\n", ans);
    return 0;
}
