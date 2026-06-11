#include <bits/stdc++.h>

using namespace std;

using LL = long long;
const LL MOD = (LL)1e9 + 7;
const LL NS = (LL)1e5 + 4;
LL N;
LL a[NS];
struct fenwick{
    vector < LL > fenw;
    LL N;
    fenwick(){}
    fenwick(LL n):N(n){
        fenw.resize(N);
    }
    void push(LL x, LL val){
        for(LL i = x; i < N; i += (i & -i)){
            fenw[i] += val;
        }
    }
    LL get(LL x){
        LL rv = 0;
        for(LL i = x; i; i -= (i & -i)){
            rv += fenw[i];
        }
        return rv;
    }
}tree;

LL Count(LL low){
    tree = fenwick(NS * 2);
    LL rv = 0, zero = 0;
    for(LL i = 1; i <= N; ++i){
        LL pl = (a[i] >= low ? 1 : -1);
        tree.push(zero + NS, 1);
        zero -= pl;
        rv += tree.get(NS * 2 - 1) - tree.get(zero + NS - 1);
    }
    return rv;
}

int main(){
    scanf("%lld", &N);
    for(LL i = 1; i <= N; ++i){
        scanf("%lld", a + i);
    }
    LL low = 1, high = (LL)1e9, mid;
    while(low < high){
        mid = (low + high) >> 1; ++mid;
        if(Count(mid) >= N * (N + 1) / 4 + N * (N + 1) / 2 % 2){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    printf("%lld\n", low);
    return 0;
}
