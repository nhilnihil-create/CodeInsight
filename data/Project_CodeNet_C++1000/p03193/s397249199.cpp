#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    int N, H, W;
    scanf("%d %d %d", &N, &H, &W);
    
    // 2. 縦 H, 横 W の板が得られるか？
    int ans = 0;
    rep(i, N){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a >= H && b >= W) ans++;
    }
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}