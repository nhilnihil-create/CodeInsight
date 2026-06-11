// 解き直し.
// https://img.atcoder.jp/nikkei2019-qual/editorial.pdf
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    int N;
    scanf("%d", &N);
    priority_queue<LL> pq;
    LL ans = 0, a, b;
    rep(i, N){
        scanf("%lld %lld", &a, &b);
        pq.push(a + b);
        ans -= b;
    }
    
    // 2. 幸福度の差は？
    bool f = (1 & N);
    while(!pq.empty() && N > 0){
        // 要素を一つ取り出す.
        LL p = pq.top();
        pq.pop();
        
        // 加算.
        if(f){
            if(N & 1)    ans += p;
        }else{
            if(!(N & 1)) ans += p;
        }
        
        // デクリメント.
        N--;
    }
    
    // 3. 出力.
    printf("%lld\n", ans);
    return 0;
    
}