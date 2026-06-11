#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define a first
#define b second

// Efficient program to print all prime factors of a given number
// https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
// 与えられた正整数についての素因数分解を計算.
// @param X: 素因数分解を行う整数.
// @return ret: 素因数分解 の 結果 を 返却.
map<LL, LL> div(LL X){
    
    // 1. X を 2で割り切れなくなるまで割っていく.
    map<LL, LL> ret;
    while(X % 2 == 0) ret[2]++, X >>= 1;
    
    // 2. X を 3以上の奇数で, 割り切れなくなるまで順次割っていく.
    repex(i, 3, sqrt(X) + 1, 2){
        while(X % i == 0){
            ret[i]++;
            X /= i;
        }
    }
    
    // 3. X が 2 より 大きな素数であれば, 追加.
    if(X > 2) ret[X]++;
    
    // 4. 出力.
    return ret;
}

int main(){
    
    // 1. 入力情報.
    LL N, P;
    scanf("%lld %lld", &N, &P);
    
    // 2. 素因数分解.
    map<LL, LL> m = div(P);
    // for(auto &p : m) printf("%lld %lld\n", p.a, p.b);
    
    // 3. 最大公約数は？
    LL ans = 1;
    for(auto &p : m){
        int l = p.b / N;
        rep(i, l) ans *= p.a;
    }
    
    // 4. 出力.
    printf("%lld\n", ans);
    return 0;
    
}