#include<bits/stdc++.h>
using ll = int_fast64_t;
#define REP(i,b,e) for(ll i=b; i<e; i++)
#define SCAN(vec) for(auto &i:vec)scanf("%ld",&i)

int main(){
        int x, y, z, k;
        scanf("%d %d %d %d", &x, &y, &z, &k);
        ll a[x], b[y], c[z];
        SCAN(a);SCAN(b);SCAN(c);
        ll d[x*y], cnt = 0;
        REP(i, 0, x) REP(j, 0, y) d[cnt++] = a[i]+b[j];
        std::sort(d, d+x*y, std::greater<ll>());
        int len = std::min(x*y, k);
        ll ans[len*z];
        cnt = 0;
        REP(i, 0, len) REP(j, 0, z) ans[cnt++] = d[i]+c[j];
        std::sort(ans, ans+len*z, std::greater<ll>());
        REP(i, 0, k) printf("%ld\n", ans[i]);
        return 0;
}