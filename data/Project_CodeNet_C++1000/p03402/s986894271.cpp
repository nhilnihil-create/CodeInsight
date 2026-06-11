#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define sqr(s) ((s) * (s))
const int inf = 0x7fffffff / 3.27;
const int maxn = 105;
int i, j, t, n, m, l, r, k, z, y, x;
int a, b;
char f[maxn][maxn];
void calc(int a, int b) {
    int i, j;
    i = 1;
    while (a > 1 && i + 5 <= n) {
        for (j = 1; j <= m; j++) {
            f[i][j] = f[i + 1][j] = f[i + 2][j] = '.';
            f[i + 3][j] = f[i + 4][j] = f[i + 5][j] = '#';
        }
        a--;
        b--;
        i += 6;
    }
    for (; i <= n; i++)
        for (j = 1; j <= m; j++) f[i][j] = '.';
    a--;
    i = 5;
    while (a > 0) {
        for (j = 1; j <= m; j += 2) {
            f[i][j] = '.';
            a--;
            if (a == 0) break;
        }
        i += 6;
    }
    i = 2;
    while (b > 0) {
        for (j = 1; j <= m; j += 2) {
            f[i][j] = '#';
            b--;
            if (b == 0) break;
        }
        i += 6;
    }
}
int main() {
    int I, T = 1;
    // scanf("%d", &T);
    for (I = 1; I <= T; I++) {
        scanf("%d%d", &a, &b);
        n = m = 100;
        calc(min(a, b), max(a, b));
        if (a > b) {
            for (i = 1; i <= n; i++)
                for (j = 1; j <= m; j++) {
                    f[i][j] = (f[i][j] == '.') ? '#' : '.';
                }
        }
        printf("%d %d\n", n, m);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) printf("%c", f[i][j]);
            printf("\n");
        }
    }
    return 0;
}