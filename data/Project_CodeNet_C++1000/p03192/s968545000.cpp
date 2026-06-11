#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    char c[10];
    scanf("%s", c);
    
    // 2. '2' の 個数.
    int ans = 0;
    rep(i, 4) if(c[i] == '2') ans++;
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}