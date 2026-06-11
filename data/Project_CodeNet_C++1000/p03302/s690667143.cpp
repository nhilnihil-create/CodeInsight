#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int a, b;
    scanf("%d %d", &a, &b);
    
    // 2. 出力.
    if(a + b == 15)      puts("+");
    else if(a * b == 15) puts("*");
    else                 puts("x");
    return 0;
    
}