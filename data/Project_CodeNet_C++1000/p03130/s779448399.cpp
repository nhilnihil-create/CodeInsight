#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
int town[4];

int main(){
    
    // 1. 入力情報.
    int a[6];
    rep(i, 6) scanf("%d", a + i);
    
    // 2. 経路情報を保存.
    rep(i, 6) town[--a[i]]++;
    
    // 3. 判定.
    // 〇 1 1 2 2
    // × 0 2 2 2
    // × 1 1 1 3
    int ans = 1;
    rep(i, 4) ans *= town[i];
    
    // 4. 出力.
    if(ans == 4) puts("YES");
    else         puts("NO");
    return 0;
    
}