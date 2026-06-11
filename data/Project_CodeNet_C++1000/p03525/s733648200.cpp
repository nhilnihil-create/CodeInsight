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

vector<int> d(13,0);
vector<bool> e(25,false);

int search( int hour ){
    if( hour == 13 ){
        int cnt = 123;
        int ret = 10200;
        Rep(i,80){
            if( e[i%24] ){
                ret = min( cnt, ret );
                cnt = 0;
            }
            cnt++;
        }
        return ret;
    }
    if( d[hour] > 2 ) return 0;
    if( d[hour] == 0 ) return search( hour+1 );
    if( d[hour] == 1){
        if( hour == 12 ) {
            e[0] = true;
            int plus = search( hour+1 );
            e[0] = false;
            return plus;
        }
        e[12+hour] = true;
        int plus = search( hour+1 );
        e[12+hour] = false;
        e[12-hour] = true;
        int minus = search( hour+1 );
        e[12-hour] = false;
        return max( plus , minus );
    }
    if( d[hour] == 2 ){
        if( hour == 0 || hour == 12 ) return 0;
        e[12+hour] = true;
        e[12-hour] = true;
        return search( hour+1 );
    }
}

int main() {

    int N;
    Scd(N);
    d[0] = 1;
    e[12] = 1;

    int a;
    Rep(i,N){
        Scd(a);
        d[a]++;
    }

    int ans = search(0);

    printf ("%d\n", ans );

    return 0;
}

