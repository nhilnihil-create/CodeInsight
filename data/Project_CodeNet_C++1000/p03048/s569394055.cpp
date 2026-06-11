#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){

    // 1. 入力情報.
    int R, G, B, N;
    scanf("%d %d %d %d", &R, &G, &B, &N);
    
    // 2. 組み合わせをカウント.
    int ans = 0;
    rep(r, (N / R) + 1){
        rep(g, (N / G) + 1){
            int b = N - R * r - G * g;
            if(b >= 0 && b % B == 0) ans++;
        }
    }
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}