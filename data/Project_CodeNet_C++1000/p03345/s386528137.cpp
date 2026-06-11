#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define rep(i,n) for(ll i=0,i##_len=(n);i<i##_len;i++)
#define rep2(i,a,b) for(ll i=(a),i##_len=(b);i<=i##_len;i++)
#define rrep(i,n) ll i=(n);ll now=-1;while(i--&&(now++||1))
#define Yes(n) cout<<((n)?Yes:No)<<"\n"
#define vll vector<ll>
#define pb push_back

using namespace std;
using ll = long long;

static inline void ignore_ret(int x) {x++;}
template<class T> bool chmax(T&a,const T&b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T&a,const T&b){if(a>b){a=b;return true;}return false;}
template<class T> T gcd_vec(vector<T>v){T r=v.at(0);for(T i=1;i<v.size();i++)r=gcd(r,v.at(i));return r;}
template<class T> T lcm_vec(vector<T>v){T r=v.at(0);for(T i=1;i<v.size();i++)r=lcm(r,v.at(i));return r;}
template<class T> T factorial(T n){if(n==0)return 1;T r=1;for(T i=2;i<=n;i++)r*=i;return r;}
template<class T> T nCr(T n,T k){return factorial<T>(n)/(factorial<T>(k)*factorial<T>(n-k));}
template<class T> T dot_product(vector<T>u,vector<T>v){T r=0;for(T i=0;i<u.size();i++)r+=u.at(i)*v.at(i);return r;}
template<class T> T sum(vector<T>v){return reduce(all(v),0LL);}

// Template ends here

void solve(ll A, ll B, ll C, ll K){
    ll ans = (K % 2) ? (B - A) : (A - B);
    if (abs(ans) <= 1e18) printf("%lld", ans);
    else printf("Unfair\n");
}

int main() {
    ll A;
    ignore_ret(scanf("%lld",&A));
    ll B;
    ignore_ret(scanf("%lld",&B));
    ll C;
    ignore_ret(scanf("%lld",&C));
    ll K;
    ignore_ret(scanf("%lld",&K));
    solve(A, B, C, K);
    return 0;
}
