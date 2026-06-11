#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);
    
    // 2. 最大で何回のコンテストを開催できるか？
    int ans = 0, a = 0, b = 0, c = 0, p;
    rep(i, N){
        scanf("%d", &p);
        if(p <= A)               a++;
        if(p >= A + 1 && p <= B) b++;
        if(p >= B + 1)           c++;
    }
    
    // 3. 出力.
    printf("%d\n", min({a, b, c}));
    return 0;
    
}