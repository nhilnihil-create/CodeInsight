#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
char s[305];
int dp[305][305][305];
int dfs(int l, int r, int x) {
    if(l >= r) {
        return r - l + 1;
    }
    if(dp[l][r][x] != -1) {
        return dp[l][r][x];
    }
    int ret = max(dfs(l + 1, r, x), dfs(l, r - 1, x));
    if(s[l] == s[r]) {
        ret = max(ret, dfs(l + 1, r - 1, x) + 2);
    } else if(x) {
        ret = max(ret, dfs(l + 1, r - 1, x - 1) + 2);
    }
    return dp[l][r][x] = ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%s%d", s + 1, &k);
    n = strlen(s + 1);
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            ans = max(ans, dfs(i, j, k));
        }
    } 
    printf("%d\n", ans);
    return 0;
}