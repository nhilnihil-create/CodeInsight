#include <bits/stdc++.h>
using namespace std;

char s[310];
int K, f[310][310][610];

int main() {
    scanf("%s %d", s + 1, &K);
    int n = strlen(s + 1);
    memset(f, -1, sizeof(f));
    function<int(int, int, int)> dfs = [&](int l, int r, int k) {
        if (r - l < 1) return r - l + 1;
        if (~f[l][r][k]) return f[l][r][k];
        f[l][r][k] = max(dfs(l + 1, r, k), dfs(l, r - 1, k));
        int t = s[l] != s[r];
        if (k >= t) f[l][r][k] = max(f[l][r][k], dfs(l + 1, r - 1, k - t) + 2);
        return f[l][r][k];
    };
    printf("%d\n", dfs(1, n, K));
    return 0;
}