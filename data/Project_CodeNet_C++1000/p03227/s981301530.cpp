#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    char c[5];
    scanf("%s", c);
    
    // 2. 出力.
    int l = strlen(c);
    if(l == 2) printf("%c%c\n", c[0], c[1]);
    else       printf("%c%c%c\n", c[2], c[1], c[0]);
    return 0;
    
}