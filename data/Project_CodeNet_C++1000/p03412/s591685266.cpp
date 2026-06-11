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

    int N;
    Scd(N);

    vector<int> a(N);
    vector<int> b(N);
    Rep(i,N){
        Scd(a[i]);
    }
    Rep(i,N){
        Scd(b[i]);
    }

    sort( a.begin(), a.end() );
    sort( b.begin(), b.end() );

    int ans = 0;
    ll dig = 0x40000000;
    for (int i = 28; dig ; i--){
        Rep(ii,N){
            a[ii] &= (dig<<1)-1;
            b[ii] &= (dig<<1)-1;
        }
        sort( a.begin(), a.end() );
        sort( b.begin(), b.end() );
        // printf ("!%d\n", dig);
        int t1,t2,t3,t4;
        int t = 0;
        Rep(ai,N){
            int l = 0; //OK
            int r = N; //NG -> [l,r)
            l = -1; r = N;
            while( r - l > 1 ){
                int m = r+l>>1;
                // printf ("%d+%d >= %lld\n", a[ai], b[m], dig );
                if( a[ai] + b[m] >= dig ){
                    r = m;
                }else{
                    l = m;
                }
            }
            t1 = l;
            l = -1; r = N;
            while( r - l > 1 ){
                int m = r+l>>1;
                // printf ("%d+%d >= %lld\n", a[ai], b[m], dig );
                if( a[ai] + b[m] >= dig*2 ){
                    r = m;
                }else{
                    l = m;
                }
            }
            t2 = l;
            l = -1; r = N;
            while( r - l > 1 ){
                int m = r+l>>1;
                // printf ("%d+%d >= %lld\n", a[ai], b[m], dig );
                if( a[ai] + b[m] >= dig*3 ){
                    r = m;
                }else{
                    l = m;
                }
            }
            t3 = l;
            l = -1; r = N;
            while( r - l > 1 ){
                int m = r+l>>1;
                // printf ("%d+%d >= %lld\n", a[ai], b[m], dig );
                if( a[ai] + b[m] >= dig*4 ){
                    r = m;
                }else{
                    l = m;
                }
            }
            t4 = l;
            t += t2-t1+t4-t3;
            // printf ("%d %d %d %d\n", t1,t2,t3,t4);
        }
        // printf ("%d\n", t);
        ans += dig * ( t&1 );
        dig >>= 1;
    }
    printf ("%d\n", ans );


    return 0;
}

