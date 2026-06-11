#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int F[305][305][305], K, n;

char ch[333];

void cmax(int &x, int y) {
    if(x < y) x = y;
}

int main() {
    scanf("%s", ch + 1);
    scanf("%d", &K);
    memset(F, 200, sizeof F);
    n = strlen(ch + 1);
    F[0][n + 1][0] = 0;
    for(int i = 0; i <= n + 1; i++)
        for(int j = n + 1; j >= 1; j--)
            for(int k = 0; k <= K; k++) {
                cmax(F[i + 1][j][k], F[i][j][k]);
                cmax(F[i][j - 1][k], F[i][j][k]);
                int tmp = ch[i + 1] != ch[j - 1];
                if(k + tmp <= K) cmax(F[i + 1][j - 1][k + tmp], F[i][j][k] + 2);
            }
    int ans = 0;
    for(int i = 2; i <= n + 1; i++)
        for(int j = 0; j <= K; j++)
            cmax(ans, F[i - 2][i][j] + 1);
    for(int i = 1; i <= n + 1; i++)
        for(int j = 0; j <= K; j++)
            cmax(ans, F[i - 1][i][j]);
    printf("%d\n", ans);
    return 0;
}