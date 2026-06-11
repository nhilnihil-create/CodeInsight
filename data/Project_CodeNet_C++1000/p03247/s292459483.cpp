#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// definition {{{ 1

// scaning {{{ 2
#define Scd(x) scanf("%d", &x)
#define Scd2(x,y) scanf("%lld%lld", &x, &y)
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

    int n;
    ll x[1000] = {},y[1000];
    ll leng[1000];

    Scd(n);

    Rep(i,n){
        Scd2(x[i],y[i]);
        leng[i] = abs(x[i]) + abs(y[i]);
    }
  
  	

    int odd = leng[0] % 2;

    Rep(i,n){
        if(leng[i] % 2 != odd){
            printf ("%d\n", -1);
            return 0;
        }
    }

  
    int ans = 31;
    ans += !odd;
    printf ("%d\n", ans);
  	ans -= !odd;

    if(!odd) printf ("%d ", 1);
    ll longer[32] = {1};
  
  	
    Rep(i,ans){
        printf("%lld", longer[i]);
              
        if( i+1 != ans) {
            printf (" ");
            longer[i+1] = longer[i];  
            longer[i+1] *= 2;
        }
    }
    printf ("\n");
  
    ans += !odd;
  
    ll pow31 = 1;
    Rep(i,31) pow31*=2;

    ll u[1000],v[1000];
    Rep(i,n){
        if(!odd) x[i]--;
        u[i] = x[i] + y[i];
        v[i] = x[i] - y[i];
        u[i] = (u[i] + (pow31 - 1)) / 2;
        v[i] = (v[i] + (pow31 - 1)) / 2;
        ll xx = 0;
        ll yy = 0;
        Rep(j,ans){
            if( !odd && j == 0) {printf ("R"); xx++ ;continue;}
            if( u[i] % 2 && v[i] % 2){
                printf ("R");
                xx += longer[j-!odd];
            }else if( u[i] % 2 == 0 && v[i] % 2){
                printf ("D");
                yy -= longer[j-!odd];
            }else if( u[i] % 2 && v[i] % 2 == 0 ){
                printf ("U");
                yy += longer[j-!odd];
            }else{
                printf ("L");
                xx -= longer[j-!odd];
            }
            u[i] /= 2;
            v[i] /= 2;
        }
        //p//rintf ("%lld,%lld", xx,yy);
        printf ("\n");
    }

    return 0;
}

