#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL A, B;

// クッキーの受け渡しを計算.
// @param k: 受け渡しの回数.
// @param b: ターン.
// @return : 再帰処理を行う.
void recursive(int k, bool b){
    if(k == 0) return;
    if(b){
        if(A & 1) A--;
        A >>= 1, B += A;
    }else{
        if(B & 1) B--;
        B >>= 1, A += B;
    }
    recursive(k - 1, !b);
}

int main(){
    
    // 1. 入力情報.
    int K;
    scanf("%lld %lld %d", &A, &B, &K);
    
    // 2. クッキーの枚数を計算.
    recursive(K, true);
    
    // 3. 出力.
    printf("%lld %lld\n", A, B);
    return 0;
    
}