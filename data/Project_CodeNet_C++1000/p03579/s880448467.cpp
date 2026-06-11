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

    int N,M;
    Scd2(N,M);

    vector<vi> e(N);

    int x,y;
    Rep(i,M){
        Scd2(x,y);
        x--,y--;
        e[y].push_back(x);
        e[x].push_back(y);
    }

    vi v(N*2);
    stack<int> s;
    s.push(0);
    while(s.size()){
        int from = s.top()%N;
        int odd = s.top()/N;
        s.pop();

        v[from+odd*N] = 1;

        for( int to : e[from] ){
            if( !odd ) to += N;
            if( v[to] ) continue;
            s.push(to);
        }
    }

    ll A = 0;
    ll B = 0;
    Rep(i,N) A += v[i];
    Rep(i,N) B += v[i+N];

    if( A == N && B == N )
        printf ("%lld\n", 1ll*N*(N-1)/2-M );
    else
        printf ("%lld\n", A*B-M );

    return 0;
}



