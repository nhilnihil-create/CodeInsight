#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    char c[55];
    scanf("%s", c);
    int l = strlen(c) - 8; // "FESTIVAL" 分 を マイナス.
    
    // 2. 出力.
    for(int i = 0; i < l; i++) printf("%c", c[i]);
    printf("\n");
    return 0;
    
}