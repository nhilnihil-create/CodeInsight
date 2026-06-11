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
#define Rep(x,y) for(int x = 0; x < (y); x++)
#define Repe(x,y,z) for(int x = z; x <(y); x++)
// }}} 2

// output {{{ 2
#define YesNo(a) (a)?printf("Yes\n"):printf("No\n");
// }}} 2

// }}} 1

int main() {

    int N;
    Scd(N);
    vector<int> a(1<<N);
    Rep(i,1<<N){
        Scd(a[i]);
    }

    using pii = pair<int,int>;
    vector<pii> dp(1<<N,pii(a[0],0));
    Rep(i,1<<N){
        dp[i].first = a[i];
    }
    vector<int> ss(4);
    Rep(j,N){
        Rep(i,1<<N){
            if( 0 == ( i & (1 << j) ) ) {
                int ji = i | (1<<j);
                ss[0] = dp[i].first;
                ss[1] = dp[i].second;
                ss[2] = dp[ji].first;
                ss[3] = dp[ji].second;
                sort(ss.begin(),ss.end());
                dp[ji].first = ss[3];
                dp[ji].second = ss[2];
            }
        }
    }

    int ma = 0;
    Repe(i,1<<N,1){
        ma = max( ma, dp[i].first + dp[i].second);
        printf ("%d\n", ma );
    }


    return 0;
}

