#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

ll k;
ll solve(vll& x, ll b){
    vll cnt(b, 0);
    rep(i, SZ(x)){
        rep(j, b){
            cnt[j] += ((x[i]>>j)&1);
        }
    }
    //dump(cnt);
    ll ret = 0;
    for(ll i = b-1; i >= 0; i--){
        if(cnt[i] >= k){
            vll y;
            rep(j, SZ(x)){
                if((x[j]>>i)&1){
                    y.emplace_back(x[j]);
                }
            }
            ret += (1ll << i);
            ret += solve(y, i);
            break;
        }
    }
    return ret;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n >> k;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    vll sum;
    rep(i, n){
        ll s = 0;
        repr(j, i, n){
            s += a[j];
            sum.emplace_back(s);
        }
    }
    sort(ALL(sum));
    cout << solve(sum, 60) << endl;
    /*
    rep(i, SZ(sum)){
        cout << std::bitset<8>(sum[i]) << endl;
    }
    */
    return 0;
}