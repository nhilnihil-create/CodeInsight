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
    if( N==3 ){
        printf ("%d %d %d\n", 2, 5, 63 );
        return 0;
    }

    const int K = 30000;

    vi a,b,c,d;

    Repe(i,K+1,1){
        if( i%6 == 0 ) d.push_back(i);
        else if( i%3 == 0 ) c.push_back(i);
        else if( i%2 == 0 ){
            if( i%3 == 1 ) b.push_back(i);
            else a.push_back(i);
        }
    }

    vi ans;
    int ai=0,bi=0,ci=0,di=0,M=N;
    if( N%2 ) ans.push_back(d[di++]), M--;
    Rep(i,M){
        if( i%4 == 0 ) ans.push_back(a[ai++]);
        else if( i%4 == 1 ) ans.push_back(b[bi++]);
        else if( i%4 >= 2 ){
            if( ci < 5000 ) ans.push_back(c[ci++]);
            else ans.push_back(d[di++]);
        }
    }

    int sum = 0;
    Rep(i,N) printf ("%d%s", ans[i], i==N-1?"\n":" " );

    return 0;
}

