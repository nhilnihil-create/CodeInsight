//bismillahir rahmanir rahim            //Author:Fayed Anik
 
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define         ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define         ll                          long  long
#define         lf                          double
#define         pb(x)                       push_back(x)
#define         ull                         unsigned long long
#define         sfl(a)                      scanf("%lld",&a)
#define         sf(a)                       scanf("%d",&a)
#define         pf(a)                       printf("%d\n",a)
#define         pfl(a)                      printf("%lld\n",a)
#define         FOR(x,n)                    for(ll x=1;x<=n;++x)
#define         pii                         pair< ll , ll >
#define         mp(a,b)                     make_pair(a,b)
#define         mod                         1000000007
#define         INF                         2e18
#define         EPS                         1e-15
#define         f1                          first
#define         f2                          second
#define         all(v)                      v.begin(),v.end()
#define         PI                          acos(-1)
#define         printminusone               printf("-1\n")
#define         bug                         printf("bug")
#define         FILEIN                      freopen("in.txt","r",stdin)
#define         FILEOUT                     freopen("out.txt","w",stdout)
 
//ll SET(ll mask,ll pos){ return mask = (mask | (1ll<<pos)); }
//ll RESET(ll mask,ll pos){ return mask = mask & ~(1ll<<pos); }
//bool CHECK(ll mask,ll pos) { return (bool) (mask & (1ll<<pos)); }
//priority_queue <ll, vector<ll>, greater<ll> > pq;

vector<ll>v;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n,t,x,y;
    sfl(n),sfl(t);
    v.clear();
    FOR(i,n){
        sfl(x),sfl(y);
        if( y<=t ){
            v.pb(x);
        }
    }
    ll sz = v.size(),ans;
    if( sz==0 ){
        printf("TLE\n");
    }
    else{
        sort(all(v));
        ans = v[0];
        pfl(ans);
    }

    return 0;
}
