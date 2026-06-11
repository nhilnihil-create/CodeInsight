#include <iostream>
#include <cstring>
using namespace std;
char s[1002]; int k;
int vis[302][302][302], dp[302][302][302];
int dfs(int l, int r, int k) {
    if (k < 0) return - 100000;
    if (l == r)return 1;
    if (l > r) return 0;
    if (vis[l][r][k]) return dp[l][r][k];
    vis[l][r][k] = 1;
    
    int mx = max(dfs(l, r, k-1), 0);

    if (s[l] == s[r]) {
        mx = max(dfs(l+1,r-1,k) + 2, mx);
    } else {
        mx = max(dfs(l+1,r-1,k), mx);
        mx = max(dfs(l+1,r-1,k-1) + 2, mx);
    }
    mx = max(dfs(l+1,r,k), mx);
    mx = max(dfs(l,r-1,k), mx);
    return dp[l][r][k] = mx;
}
int main() {
    scanf("%s %d", s+1, &k);
    int n = strlen(s+1);
    int ans = dfs(1,n,k);
    printf("%d\n", ans);
}




