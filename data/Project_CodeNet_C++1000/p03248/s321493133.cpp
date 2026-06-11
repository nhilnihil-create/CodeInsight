#include <bits/stdc++.h>
using namespace std;
#define N 100010
int i,j,k,m,n,x,t,y,vis[N],a[N];
char s[N];
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (i = 1; i <= n; ++i)vis[i] = (s[i] == '1');
    if (!vis[1] || !vis[n - 1] || vis[n])return puts("-1"), 0;
    for (i = 2; i < n - 1; ++i)if (vis[i] != vis[n - i])return puts("-1"), 0;
    for (x = 0, i = 1; i <= n; ++i) {
        if (vis[i])while (x > 0)printf("%d %d\n", a[x--], i);
        if (i != n)a[++x] = i;
    }
    while (x > 0)printf("%d %d\n", a[x--], n);
}
