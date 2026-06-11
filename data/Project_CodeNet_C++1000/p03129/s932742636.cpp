#include <bits/stdc++.h>
using namespace std;

int main(){
    
    // 1. 入力情報.
    int N, K;
    scanf("%d %d", &N, &K);
    
    // 2. 差が1の整数を, ともに選ばないように選べる個数.
    int count = N / 2;
    if(N & 1) count++;
    
    // 3. 出力
    if(count >= K) printf("%s\n", "YES");
    else           printf("%s\n", "NO");
    return 0;
    
}