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
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T> >;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define repb(i, n) for(ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for(ll i = (a); i < (b); i++)
#define reprb(i, a, b) for(ll i = (a)-1; i >= (b); i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1000000007;
const ll INF = 100000000000000000LL;
inline ll GCD(ll a, ll b){ return b?GCD(b, a % b):a; }
inline ll LCM(ll a, ll b){ return a/GCD(a, b)*b; }
inline ll powint(unsigned long long x, ll y){ ll r=1; while(y){ if(y&1) r*=x; x*=x; y>>=1; } return r; }
inline ll powmod(ll x, ll y, ll m = MOD){ ll r=1; while(y){ if(y&1) r*=x; x*=x; r%=m; x%=m; y>>=1; } return r; }
template<class S, class T>inline bool chmax(S &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class S, class T>inline bool chmin(S &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin >> n;
    vll a(n);
    rep(i, n){
        cin >> a[i];
    }
    vll sa(n);
    sa[0] = a[0];
    repr(i, 1, n){
        sa[i] = sa[i-1] + a[i];
    }
    
    auto cond_l = [&](ll x, ll q){
        return abs(sa[q]-(sa[x]<<1));
    };
    auto cond_r = [&](ll x, ll q){
        return abs((sa[n-1]-sa[q])-((sa[x]-sa[q])<<1));
    };
    rep(i, n){
        repr(j, i+1, n-1){
            dump(i, j, cond_r(j, i));
        }
    }
    
    ll ans = INF;
    repr(q, 1, n-2){
        ll ansl = INF, ansl_i = 0;
        ll ansr = INF, ansr_i = 0;
        vll sum(4);
        // [lb, ub]三分探索
        // 値が大きい方の外側を捨てる
        {
            ll lb = 0, ub = q-1;
            while(ub - lb > 3){
                ll lm = ((lb<<1) + ub)/3;
                ll rm = (lb + (ub<<1))/3;
                if(cond_l(lm, q) < cond_l(rm, q)){
                    ub = rm;
                }else{
                    lb = lm;
                }
            }
            repr(x, lb, ub+1){
                if(chmin(ansl, cond_l(x, q))){
                    ansl_i = x;
                }
            }
            sum[0] = sa[ansl_i];
            sum[1] = sa[q]-sa[ansl_i];
        }
        {
            ll lb = q+1, ub = n-2;
            while(ub - lb > 3){
                ll lm = ((lb<<1) + ub)/3;
                ll rm = (lb + (ub<<1))/3;
                if(cond_r(lm, q) < cond_r(rm, q)){
                    ub = rm;
                }else{
                    lb = lm;
                }
            }
            repr(x, lb, ub+1){
                if(chmin(ansr, cond_r(x, q))){
                    ansr_i = x;
                }
            }
            sum[2] = sa[ansr_i]-sa[q];
            sum[3] = sa[n-1]-sa[ansr_i];
        }
        chmin(ans, *max_element(ALL(sum))-*min_element(ALL(sum)));
        dump(sum, *max_element(ALL(sum))-*min_element(ALL(sum)));
    }
    cout << ans << endl;
    return 0;
}