#include <stdio.h>
#define N (300010)
int n,a, b;
int ans[N];
int main(){
    scanf("%d%d%d", &n, &a, &b);
    if (a+b-1 > n || 1ll*a*b < n){
        printf("-1\n");
        return 0;
    }
    for (int t = 1; t <= b; ++t){
        int c = n-1ll*t*a-(b-t-1);
        if (c >= 1 && c <= a){
            int cnt = n, pos = 0;
            for (int i = 1; i <= t; ++i){
                for (int j = a; j; --j){
                    ans[pos + j] = cnt--;
                }
                pos += a;
            }
            for (int i = 1; i <= b-t-1; ++i){
                ans[++pos] = cnt--;
            }
            for (int i = c; i; --i){
                ans[pos+i] = cnt--;
            }
            break;
        }
    }
    for (int i = 1; i <= n; ++i){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
}