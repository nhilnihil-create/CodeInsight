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

// {{{ Union Find  to use UFinit(n) for 0-n UFs

int UFpare[100004];
int UFrank[100004];
int UFdist[100004];
void UFinit(int n){
    for (int i = 0; i <= n; i++) {
        UFpare[i] = i;
        UFrank[i] = 0;
        UFdist[i] = 0;
    }
}
int UFroot( int x ){
    if( UFpare[x] == x ) return x;
    else{
        int r = UFroot(UFpare[x]);
        UFdist[x] += UFdist[UFpare[x]];
        return UFpare[x] = UFroot(UFpare[x]);
    }
}
int UFdista( int x ){
    UFroot(x);
    return UFdist[x];
}
int UFdiff( int x, int y){
    return UFdista(y) - UFdista(x);
}
bool UFunion( int x , int y , int z ){
    z += UFdista(x); z -= UFdista(y);
    x = UFroot(x);
    y = UFroot(y);
    if( x == y ) return false;
    if( UFrank[x] < UFrank[y] ) swap(x,y), z = -z;
    if ( UFrank[x] == UFrank[y] ) UFrank[x]++;
    UFpare[y] = x;
    UFdist[y] = z;
    return true;
}
bool UFsame( int x, int y){
    return UFpare[x] == UFpare[y];
}

/*
 * UFinit(n) := initialize Union Find with n UFs( must operate )
 * UFpare[] = root of node
 * UFrank[] = rank of root
 * UFroot(x) := return root of node
 * UFunion(x,y) := unite two root in a root
 * UFsame(x,y) := return two root is same
 */
// }}}

int main() {

    int n,m;
    int l,r,d;
    int x[100003] = {};
    bool ans = 1;


    Scd2(n,m);
    UFinit(n);
    Rep(i,m){
        Scd3(l,r,d);
        if( !ans ) continue;
        if( !UFunion(l,r,d) ){
            //    printf ("%d\n", UFdiff(l,r));
            if( UFdiff(l,r) != d ){
                ans= false;
            }
        }
    }


    YesNo(ans);

    return 0;
}

