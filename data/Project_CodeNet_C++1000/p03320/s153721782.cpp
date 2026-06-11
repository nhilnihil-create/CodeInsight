#include <bits/stdc++.h>
 
#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)
 
#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=(int)(a)-1;i>=(int)(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)
 
#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
 
// #define DEBUG
 
#ifdef DEBUG
    #define dump(...) fprintf(stderr, __VA_ARGS__)
#else
    #define dump(...)
#endif
 
template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}
 
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
 
const double EPS = 1e-10;
const double PI = acos(-1.0);
const ll inf =1LL << 62;
const ll mod=1000000007LL;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
 
 
ll extgcd(ll a,ll b,ll& x,ll& y){x=1,y=0;ll g=a;if(b!=0) g=extgcd(b,a%b,y,x),y-=a/b*x;return g;}
ll ADD(const ll &a, const ll &b,const ll &mod) { return (a+b)%mod;}
ll SUB(const ll &a, const ll &b,const ll &mod) { return (a-b+mod)%mod;}
ll MUL(const ll &a, const ll &b,const ll &mod) { return (1LL*a*b)%mod;}
ll DIV(const ll &a, const ll &b,const ll &mod) {ll x,y; extgcd(b,mod,x,y);return MUL(a,(x+mod)%mod,mod);}
 
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dice(1,6);
uniform_real_distribution<double> score(0.0,10.0);
 
inline int sn(ll n){
    int ret = 0;
    while(n != 0) ret += (n % 10), n /= 10;
    return ret;
}

using R = long double;

ll f(ll n){
    ll ret = n;

    rep(d, 16){
        ll p = (ll)pow(10., d);
        rep(i, n / p % 10, 10){
            ll cur = ret / (p * 10) * (p * 10) + i * p + (p - 1LL);
            if(cur * sn(ret) < ret * sn(cur)){
                ret = cur;
            }
        }
    }

    return ret;
}
 
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    int K; cin >> K;
    ll cur = 1;
    rep(i, K){
        cout << cur << endl;
        cur = f(cur + 1);
    }
 
    return 0;
}
