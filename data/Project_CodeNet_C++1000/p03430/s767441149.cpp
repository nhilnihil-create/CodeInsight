#include <bits/stdc++.h>
using namespace std;
const int N = 300;

char ch[N+5]; int f[N+5][N+5][N+5], k, n;

void work() {
    scanf("%s%d", ch+1, &k); n = strlen(ch+1);
    for (int i = 1; i <= n; i++) f[i][i][0] = 1;
    for (int l = 1; l <= n; l++)
    for (int i = 1; i+l <= n; i++)
        for (int p = 0, j = i+l; p <= k; p++) {
        f[i][j][p] = max(f[i+1][j][p], f[i][j-1][p]);
        if (ch[i] == ch[j]) f[i][j][p] = max(f[i][j][p], f[i+1][j-1][p]+2);
        if (p) f[i][j][p] = max(f[i][j][p], f[i+1][j-1][p-1]+2);
        }
    int ans = 0;
    for (int i = 0; i <= k; i++) ans = max(ans, f[1][n][i]);
    printf("%d\n", ans);
}
int main() {work(); return 0; }
/*
最后的lcs中l<r的部分确定下来，l>r的部分肯定是跟前者对称的（如果有更优的话那前面一部分肯定也会选更优的） 
*/