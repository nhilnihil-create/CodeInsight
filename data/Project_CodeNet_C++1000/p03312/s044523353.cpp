#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// template {{{  0 
// using {{{ 1
using ll = long long int;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vii = vector<pii>;
using vll = vector<pll>;
// }}} 1
// definition {{{ 1
// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define Scll(x) scanf("%lld", &x)
#define Scll2(x,y) scanf("%lld%lld", &x, &y)
#define Scll3(x,y,z) scanf("%lld%lld%lld", &x, &y, &z)
#define Scc(c) scanf("%c", &c);
#define Scs(s) scanf("%s", s);
#define Scstr(s) scanf("%s", &s);
// }}} 2
// constants {{{ 2
#define EPS (1e-7)
#define INF (2e9)
#define PI (acos(-1))
// }}} 2
// systems {{{ 2
#define Repe(x,y,z) for(ll x = z; x < y; x++)
#define Rep(x,y) Repe(x,y,0)
#define RRepe(x,y,z) for(ll x = y-z-1; x >= 0; x--)
#define RRep(x,y) RRepe(x,y,0)
// }}} 2
// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n")
#define YESNO(a) (a)?printf("YES\n"):printf("NO\n")
// }}} 2
// }}} 1
// input {{{ 1
// }}} 1
// }}} 0

int main() {

    int N;
    Scd(N);

    vl a(N);
    vl t(N+1);
    Rep(i,N){
        Scll(a[i]);
        t[i+1] = t[i]+a[i];
    }

    ll p=a[0],q=a[1];
    ll r=a[2],s=t[N]-t[3];

    ll pqsa = abs(p-q);
    ll rssa = abs(r-s);

    ll pqi = 1;
    ll rsi = 3;


    Repe(i,N,3){
        r += a[i];
        s -= a[i];
        if( abs(r-s) < rssa ){
            rsi = i+1;
            rssa = abs(r-s);
        }else{
            r -= a[i];
            s += a[i];
            break;
        }
    }

    ll ans = INF*INF;
    // printf ("%lld,%lld,%lld,%lld\n", p,q,r,s );
    ans = min( ans, max(max(p,q),max(r,s))-min(min(p,q),min(r,s)) );

    Repe(i,N-1,2){
        q += a[i];
        pqsa = abs(p-q);
        while( abs((p+a[pqi])-(q-a[pqi])) < pqsa ){
            p += a[pqi]; q -= a[pqi]; pqi++; pqsa = abs(p-q);
        }
        r -= a[i];
        rssa = abs(r-s);
        while( abs((r+a[rsi])-(s-a[rsi])) < rssa ){
            r += a[rsi]; s -= a[rsi]; rsi++; rssa = abs(r-s);
        }
        // printf ("%lld,%lld,%lld,%lld\n", p,q,r,s );
        ans = min( ans, max(max(p,q),max(r,s))-min(min(p,q),min(r,s)) );
    }

    printf ("%lld\n", ans );
    return 0;
}

