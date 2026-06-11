#include <bits/stdc++.h>
using namespace std;

const int N = 1005, K = 31;

int n, x[N], y[N], r[N][K + 1], v[K + 1];

void f(int x, int y, int z, int *r, int w){
    if(x == K) return;
    if(z > y){
        r[x] |= w;
        f(x + 1, y + v[x], z, r, w);
    }
    else f(x + 1, y - v[x], z, r, w);
}

int main(){
    scanf("%d", &n);
    for(int i = 0, z, w; i < n; i++){
        scanf("%d%d", &z, &w);
        x[i] = z + w;
        y[i] = z - w;
        if((x[i] & 1) != (x[0] & 1)){ puts("-1"); return 0; }
    }
    if(~x[0] & 1){
        v[K] = 1;
        for(int i = 0; i < n; i++){
            x[i]--;
            y[i]--;
            r[i][K] = 3;
        }
    }
    for(int i = 0; i < K; i++) v[i] = (1 << (K - 1 - i));
    printf("%d\n", K + v[K]);
    for(int i = 0; i < K + v[K]; i++) printf("%d ", v[i]); puts("");
    for(int i = 0; i < n; i++){
        f(0, 0, x[i], r[i], 1);
        f(0, 0, y[i], r[i], 2);
        for(int j = 0; j < K + v[K]; j++) putchar("LUDR"[r[i][j]]);
        puts("");
    }
}