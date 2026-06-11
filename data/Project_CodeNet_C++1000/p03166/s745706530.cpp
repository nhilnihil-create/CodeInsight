#include <bits/stdc++.h>
#define M 100005
using namespace std;
vector<int> a[M];
bool vis[M];
int dp[M];
int dfs(int u){
    vis[u] = 1;
    int maxi = 0;
    for(int v : a[u])
        if(!vis[v])
            maxi = max(maxi, dfs(v) + 1);
        else 
            maxi = max(maxi, dp[v] + 1);
    dp[u] = maxi;
    return dp[u];
}
int main(){
    //freopen("data.inp", "r", stdin);
    //freopen("data.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans, dp[i]);
    printf("%d", ans);
    return 0;
}