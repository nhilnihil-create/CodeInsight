#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = ll(1e18);

int n;
ll s, m = inf;

int main(){
    scanf("%d", &n);
    for(ll x, y; n--; ){
        scanf("%lld%lld", &x, &y);
        if(x > y) m = min(m, y);
        s += x;
    }
    printf("%lld\n", max(0LL, s - m));
}