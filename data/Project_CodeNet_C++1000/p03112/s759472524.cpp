#include<bits/stdc++.h>
using ll = int_fast64_t;

int main(){
        ll a, b, q;
        scanf("%ld %ld %ld", &a, &b, &q);

        std::vector<ll> shrine(a+2);
        shrine[0]=-1e18; shrine[a+1]=1e18;
        for(ll i=1; i<=a; i++) scanf("%ld", &shrine[i]);

        std::vector<ll> temple(b+2);
        temple[0] = -1e18; temple[b+1] = 1e18;
        for(ll i=1; i<=b; i++) scanf("%ld", &temple[i]);


        for(ll i=0; i<q; i++){
                ll x;
                scanf("%ld", &x);

                ll tmps = std::lower_bound(shrine.begin(), shrine.end(), x) - shrine.begin();
                ll tmpt = std::lower_bound(temple.begin(), temple.end(), x) - temple.begin();

                ll mins=shrine[tmps-1]-x, maxs=shrine[tmps]-x;
                ll mint=temple[tmpt-1]-x, maxt=temple[tmpt]-x;

                ll ltol = -std::min(mins, mint), rtor = std::max(maxs, maxt);
                ll ltor = std::min(maxt-mins*2, maxs-mint*2), rtol = std::min(maxt*2-mins, maxs*2-mint);

                printf("%ld\n", std::min({ltol, rtor, ltor, rtol}));
        }
        return 0;
}