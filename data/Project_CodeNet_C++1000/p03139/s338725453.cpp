#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    
    // 2. 新聞X, Y の 両方購読している人数の最大, 最小は？
    int X = min(A, B);
    int Y = max(0, A + B - N);
    
    // 3. 出力.
    printf("%d %d\n", X, Y);
    return 0;
    
}