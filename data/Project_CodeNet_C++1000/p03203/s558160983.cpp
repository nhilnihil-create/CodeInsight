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

int main() {

    int h,w,n;
    Scd3(h,w,n);
    int x,y;
    multimap<int,int> c;
    multimap<int,int> d;

    Rep(i,n){
        Scd2(x,y);
        if( x >= y ){
            c.insert(make_pair(x-y,x));
            d.insert(make_pair(x-y,x));
        }
    }

    int ans = h+1;
    int mx = h;
    int pre = 1;
    Rep(i,w+h+1){
        mx = h+1;
        while( c.find(i) != c.end() ){
            auto it = c.find(i);
            //printf ("!%d,%d\n", it->first , it->second);
            mx = min(mx,it->second);
            c.erase(it);
        }
        //printf ("%d -> %d\n", i , mx );

        i++;
        while( d.find(i) != d.end() ){
            auto it = d.find(i);
            if( mx >= it->second ){
                //printf ("!!%d\n", it->second);
                ans = min(ans,it->second);
            }
            d.erase(it);
        }
        i--;
    }
    printf ("%d\n", ans-1);

    return 0;
}

