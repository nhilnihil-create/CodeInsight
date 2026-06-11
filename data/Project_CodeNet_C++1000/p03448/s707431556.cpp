#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, x;
    scanf ("%d %d %d %d", &a, &b, &c, &x);
    int ans = 0;
    int i, j, k;
    for(i = 0; i <= a; i++) {
        for(j = 0; j <= b; j++) {
            for(k = 0; k <= c; k++) {
                if(i * 500 + j * 100 + k * 50 == x) ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}