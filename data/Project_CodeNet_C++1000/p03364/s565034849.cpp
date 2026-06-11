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

using llu = unsigned int;

llu power( llu b, llu i ){
    llu r = 1;
    while( i ){
        if( i&1 ) r *= b;
        i >>= 1;
        b *= b;
    }
    return r;
}

int main() {

    int N;
    Scd(N);

    char s[312][312];

    Rep(i,N) Scs(s[i]);

    llu hash = 0;
    llu roll = 1000000007;
    llu roll2 = 998244353;
    llu rollN = power(roll,N);
    llu roll2N = power(roll2,N);
    llu  vh[300][300];
    llu  hh[300][300];
    llu vhh[300][300];
    llu hhh[300][300];

    Rep(i,N){
        hash = 0;
        Rep(j,N) hash = hash*roll + s[i][j];
        Rep(j,N){
            hh[i][j] = hash;
            hash = hash*roll - s[i][j]*rollN + s[i][j];
        }
    }
    Rep(j,N){
        hash = 0;
        Rep(i,N) hash = hash*roll2 + hh[i][j];
        Rep(i,N){
            hhh[i][j] = hash;
            hash = hash*roll2 - hh[i][j]*roll2N + hh[i][j];
        }
    }
    Rep(j,N){
        hash = 0;
        Rep(i,N) hash = hash*roll + s[i][j];
        Rep(i,N){
            vh[i][j] = hash;
            hash = hash*roll - s[i][j]*rollN + s[i][j];
        }
    }
    Rep(i,N){
        hash = 0;
        Rep(j,N) hash = hash*roll2 + vh[i][j];
        Rep(j,N){
            vhh[i][j] = hash;
            hash = hash*roll2 - vh[i][j]*roll2N + vh[i][j];
        }
    }

    int ans = 0;
    Rep(i,N) Rep(j,N){
        if( vhh[i][j] == hhh[i][j] ) ans++;
    }
    printf ("%d\n", ans );

    return 0;
}



