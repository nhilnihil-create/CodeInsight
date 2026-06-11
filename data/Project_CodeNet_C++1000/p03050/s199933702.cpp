#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define REP(i,x) for (int i=0;i<x;i++)
#define REPP(i,x,y) for (int i=x;i<=y;i++)
#define SI(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define MX3(x,y,z) max({x,y,z})
#define MX4(x,y,z,p) max({x,y,z,p})
#define MX5(x,y,z,p,q) max({x,y,z,p,q})
#define MN3(x,y,z) min({x,y,z})
#define MN4(x,y,z,p) min({x,y,z,p})
#define MN5(x,y,z,p,q) min({x,y,z,p,q})
#define amax(x,y) x=max(x,y)
#define amin(x,y) x=min(x,y)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
// #####################################################################

void solve() {

    ll n;
    SL(n);
    ll ans = 0;
    for(ll i = 1 ; i*i <= n ; i++) {
        if(n % i == 0) {
            ll x = n / i - 1;
            if(x == 0) continue;
            if(n / x == n % x) ans += x;
        }
    }
    printf("%lld\n", ans);
}

void init() {
    


}

int main () {
    init();
    solve();
    return 0;
}


