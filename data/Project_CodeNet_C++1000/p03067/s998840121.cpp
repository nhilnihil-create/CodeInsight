#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報取得.
    int A, B ,C;
    scanf("%d %d %d", &A, &B, &C);
    
    // 2. 家1 -> 家3 -> 家2 であるかを判定.
    bool ok = false;
    if(A < C && C < B) ok = true;
    if(B < C && C < A) ok = true;
    
    // 3. 出力.
    if(ok) printf("%s\n", "Yes");
    else   printf("%s\n", "No");
    return 0;
    
}