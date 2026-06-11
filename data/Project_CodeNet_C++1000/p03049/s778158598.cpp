// rand_09.txt, rand_10.txt, rand_24.txt, rand_37.txt
// rand_13.txt, rand_14.txt, rand_25.txt, rand_26.txt の WA回避のためロジック修正.
#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){

    // 1. 入力情報.
    int N, A = 0, B = 0, AB = 0, ans = 0;
    scanf("%d", &N);
    rep(i, N){
        char c[22];
        scanf("%s", c);
        int l = strlen(c);
        rep(j, l - 1) if(c[j] == 'A' && c[j + 1] == 'B') ans++;
        
        // 'A' で 終わる 文字列 の 個数.
        if(c[l - 1] == 'A' && c[0] != 'B') A++;
        
        // 'B' から 始まる 文字列 の 個数.
        if(c[l - 1] != 'A' && c[0] == 'B') B++;
        
        // 'A' で 終わり, 'B' から 始まる 文字列 の 個数.
        if(c[l - 1] == 'A' && c[0] == 'B') AB++;
    }
    
    // 2. 文字列 "AB" の 個数 を カウント.
    if(A > B)  ans += B + AB;
    if(A < B)  ans += A + AB;
    if(A == B) ans += A + AB - 1 * (AB > 0 && A == 0);
    // printf("A=%d B=%d AB=%d\n", A, B, AB);
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}