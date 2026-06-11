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

    static char t[333333];
    Scs(t);
    int N = strlen(t);

    vi s(N+1);

    Rep(i,N){
        s[i+1] ^= s[i] ^ (1<<(t[i]-'a'));
    }

    auto popn = []( int b ){
        int p = 0;
        while(b) p++, b -= (-b)&b;
        return p;
    };
    vi dp(N+1,INF);
    vi tmp(1<<26,INF);
    dp[0] = 0;
    tmp[0] = 0;

    Repe(i,N+1,1){
        dp[i] = min( tmp[s[i]]+1, dp[i] );
        Rep(j,'z'-'a'+1){
            dp[i] = min( tmp[s[i]^(1<<j)]+1, dp[i] );
        }
        tmp[s[i]] = min( tmp[s[i]], dp[i] );
    }

    // Rep(i,N){
    //     printf ("%d\n", dp[i] );
    // }
    printf ("%d\n", dp[N] );

    return 0;
}

