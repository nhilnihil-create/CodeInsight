#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    int q;
    ll a, b;
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        scanf("%lld%lld", &a, &b);
        ll x = a*b;
        
        ll r = (ll)sqrt(x);
        ll ans = r*2 - 1;
        if(r * (r+1) >= x) ans--;
        if(r * r == x && a != b) ans--;

        printf("%lld\n", ans);
    }

    return 0;
}