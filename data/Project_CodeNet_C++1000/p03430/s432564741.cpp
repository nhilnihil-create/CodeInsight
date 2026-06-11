#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N (305)
int f[N][N][N];
char s[N];
int kk;
int main(){
    scanf("%s%d", s+1, &kk);
    int n = strlen(s+1);
    for (int i = 1; i <= n; ++i){
        for (int j = n; j >= i; --j){
            f[i][j][0] = max(f[i-1][j][0], f[i][j+1][0]);
            if (s[i] == s[j]){
                f[i][j][0] = max(f[i][j][0], f[i-1][j+1][0]+1);
            }
        }
    }
    for (int k = 1; k <= kk; ++k){
        for (int i=1; i <= n; ++i){
            for (int j = n; j>=i; --j){
                f[i][j][k] = max(max(f[i-1][j][k], f[i][j+1][k]), f[i-1][j+1][k-(s[i]!=s[j])]+1);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        ans = max(2*f[i][i+1][kk], ans);
        ans = max(2*f[i-1][i+1][kk]+1, ans);
    }
    printf("%d\n", ans);
}