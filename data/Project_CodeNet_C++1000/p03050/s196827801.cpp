// C++(GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define a first
#define b second
#define all(x) x.begin(), x.end()

// 与えられた正の整数のすべての約数を抽出.
// @param X: 約数を抽出したい正の整数.
// @return ret: すべての約数.
vector<LL> div(LL X){
    vector<LL> ret;
    ret.pb(1);
    for(LL d = 2; d * d <= X; d++){
        if(X % d == 0){
            ret.pb(d);
            if(d * d != X) ret.pb(X / d);
        }
    }
    if(X > 1) ret.pb(X);
    sort(all(ret));
    return ret;
}

int main(){
    
    // 1. 入力情報.
    LL N;
    scanf("%lld", &N);
    
    // 2. N の 約数 を 保存.
    vector<LL> divisors = div(N);
    
    // 3. お気に入りの数を抽出.
    // N = q * m + q となる 素因数q から, m を 逆算.
    // 但し, m は q より大きい値として抽出.
    LL ans = 0;
    for(auto &q : divisors){
        LL m = N / q - 1;
        // printf("q=%lld m=%lld\n", q, m);
        if(m > q) ans += m;
    }
    
    // 4. 出力.
    printf("%lld\n", ans);
    return 0;
    
}