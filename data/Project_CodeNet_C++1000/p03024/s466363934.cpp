#include <bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
int a[10];

int main(){

    // 1. 入力情報.
    char c[22];
    scanf("%s", c);
    
    // 2. 'o' を カウント.
    int o = 0;
    int l = strlen(c);
    rep(i, 15){
        if(i < l && c[i] == 'o') o++;
        if(i >= l)               o++;
    }
    
    // 3. 出力.
    printf("%s\n", (o >= 8) ? "YES" : "NO");
    return 0;
    
}