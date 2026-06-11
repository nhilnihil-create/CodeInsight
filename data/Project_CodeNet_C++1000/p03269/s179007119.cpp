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

    int L;
    Scd(L);
    vi pre(L);
    L--;

    int N = 0,M = 0;
    int ni = 1;
    int ew = 1;
    vector<vii> e(25);
    while( ni < 19 && ew*2-1 <= L ){
        e[ni].push_back({ni+1,ew});
        e[ni].push_back({ni+1,0});
        M+=2;
        ew *= 2; ni++;
    }
    N = ni+1;

    while( L >= 0 ){
        if( L >= ew-1 ){
            e[ni].push_back({N,L-ew+1});
            M++;
            L -= ew;
        }else{
            ew /= 2; ni--;
        }
    }

    printf ("%d %d\n", N, M);
    Rep(i,21){
        for( pii p : e[i] ){
            printf ("%lld %d %d\n", i, p.first, p.second );
        }
    }

    stack<pii> s;
    s.push({1,0});
    while(s.size()){
        int from = s.top().first;
        int dis = s.top().second;
        s.pop();
        if( from == N ){
            if( pre[dis] ) printf ("!!!\n");
            pre[dis]++;
        }
        for( pii t : e[from] ){
            int to = t.first;
            int ddis = dis + t.second;
            s.push({to,ddis});
        }
    }
    for( int t : pre ){
        if( t==0 ) printf ("!!!\n");
    }

    return 0;
}

