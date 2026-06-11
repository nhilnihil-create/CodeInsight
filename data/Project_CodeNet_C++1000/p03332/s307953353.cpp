#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// definition {{{ 1

// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)

#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%llu%llu", &x, &y)
#define Scll3(x,y,z) scanf("%lld%lld%lld", &x, &y, &z)

#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2

// constants {{{ 2
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
// }}} 2

// systems {{{ 2
#define Repe(x,y,z) for(ll x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
// }}} 2

// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n");
// }}} 2

// }}} 1

ll mod = 998244353;

// PowMod( base, index, modulo) return base ** index % modulo {{{
// PowMod = base ** index % mod ( natural numbers )
ll PowMod( ll base, ll index, ll modulo = mod ){
    if( index == 0 ) return 1;
    // O( log(index) )
    if( index % 2 ){
        return base * PowMod(base, index - 1, modulo) % modulo;
    }else{
        ll Phalf = index / 2;
        ll half = PowMod(base, Phalf, modulo);
        return half * half % modulo;
    }
}
// }}}

int main() {

    ll N,A,B;
    Scll3(N,A,B);
    ll K;
    Scll(K);

    vector<ll> f(N+1);
    f[0] = 1;
    vector<ll> rf(N+1);
    rf[0] = 1;

    Rep(i,N){
        f[i+1] = f[i]*(i+1)%mod;
        rf[i+1] = rf[i]*PowMod(i+1,mod-2)%mod;
        // printf ("%lld %lld\n", f[i], rf[i] );
    }

    ll ans = 0;
    ll n = N;
    Rep(i,N+1){
        if( A * i > K ) break;
        if( (K-A*i) % B == 0 ){
            ll b = (K-A*i)/B;
            if( b > N ) continue;
            // N_C_b * ?
            ll plus = f[n];
            plus *= rf[b];
            plus %= mod;
            plus *= rf[n-b];
            plus %= mod;

            plus *= f[n];
            plus %= mod;
            plus *= rf[i];
            plus %= mod;
            plus *= rf[n-i];
            plus %= mod;


            ans += plus;
            ans %= mod;
        }
    }

    printf ("%lld\n", ans );

    return 0;
}

