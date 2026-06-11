
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll mod = 998244353;
const double error = 1e-7;
const double PI = acos(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

#define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
#define hoise cerr<<"hoise\n"
#define tham getchar()
mt19937 rng((unsigned int) chrono::system_clock::now().time_since_epoch().count());

inline ll MOD(ll x, ll m = mod)
{
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9+5;
const ll infl = 1e18+1;
const int nmax = 2e5+5;
///====================== template =========================

int main(){
    FASTIO;
    int tc;
    cin>>tc;
    for(int cs = 1; cs<=tc; cs++){
        ll a, b, c, d;
        cin>>a>>b>>c>>d;

        if(a < b) {
            cout<<"No\n";
            continue;
        }

        a %= b;

        if(a > c){
            cout<<"No\n";
            continue;
        }

        ll del = d - b;
        if(del < 0){
            cout<<"No\n";
            continue;
        }

        if(del == 0){
            cout<<"Yes\n";
            continue;
        }

        del = __gcd(del, b);

        if((b-a+del-1)/del - (c-a)/del > 1){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }

}
