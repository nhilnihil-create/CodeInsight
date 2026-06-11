#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

// definition {{{ 1

// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%d%d", &x, &y)
#define Scd3(x,y,z) scanf("%d%d%d", &x, &y, &z)

#define Scll(x) scanf("%llu", &x)
#define Scll2(x,y) scanf("%llu%llu", &x, &y)
#define Scll3(x,y,z) scanf("%llu%llu%llu", &x, &y, &z)

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
#define Rep(x,y) for(int x = 0; x < y; x++)
#define Repe(x,y,z) for(int x = z; x < y; x++)
// }}} 2

// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n");
// }}} 2

// }}} 1

using vi = vector<int>;
using vvi = vector<vi>;

int main() {

    int N,M;

    Scd2(N,M);

    vvi e( N );
    vi r( N,0 );

    int a,b;
    Rep(i,N+M-1){
        Scd2(a,b);
        a--,b--;
        e[a].push_back(b);
        r[b]++;
    }

    int head = 0;
    Rep(i,N){
        if( r[i] == 0 ) head = i;
    }

    vector<int> s(N,0);
    deque<int> d;

    d.push_back(head);

    while( !d.empty() ){
        int from = d.front();
        d.pop_front();
        for( int to : e[from] ){
            if( --r[to] == 0 ){
                s[to] = from+1;
                d.push_back(to);
            }
        }
    }

    Rep(i,N){
        printf ("%d\n", s[i] );
    }





    return 0;
}

