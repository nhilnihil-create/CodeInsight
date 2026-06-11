#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define MSET(x,y) memset(x,y,sizeof(x))
#define M 100005
using namespace std;
int n,k,a[105],dp[M];
bool vis[M];
int dfs(int cur) {
    if (vis[cur]) return dp[cur];
    if (cur == 0) return 0;
    vis[cur] = true;
    int &res = dp[cur];

    res = 0;
    REP(i,1,n) if(cur >= a[i] && !dfs(cur-a[i])) {
        res = 1;
    }
    return res;
}
int main()
{
    scanf("%d %d", &n, &k);
    REP(i,1,n) scanf("%d", &a[i]);
    printf("%s\n", dfs(k) ? "First" : "Second");
    return 0;
}
