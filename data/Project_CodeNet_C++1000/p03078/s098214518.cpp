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
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll MOD = 1000000007LL;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
 
ll extgcd(ll a,ll b,ll& x,ll& y){x=1,y=0;ll g=a;if(b!=0) g=extgcd(b,a%b,y,x),y-=a/b*x;return g;}
ll ADD(const ll &a, const ll &b, const ll mod=MOD) { return (a+b)%mod;}
ll SUB(const ll &a, const ll &b, const ll mod=MOD) { return (a-b+mod)%mod;}
ll MUL(const ll &a, const ll &b, const ll mod=MOD) { return (1LL*a*b)%mod;}
ll DIV(const ll &a, const ll &b, const ll mod=MOD) {ll x,y; extgcd(b,mod,x,y);return MUL(a,(x+mod)%mod,mod);}
 
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int X, Y, Z, K; cin >> X >> Y >> Z >> K;
    vll a(X), b(Y), c(Z);
    for(auto& e : a) cin >> e;
    for(auto& e : b) cin >> e;
    for(auto& e : c) cin >> e;

    vll ab;
    for(auto& e1 : a){
        for(auto& e2 : b){
            ab.emplace_back(e1 + e2);
        }
    }

    sort(_all(ab), greater<ll>());
    using Elem = tuple<ll, int, int>;
    priority_queue<Elem> q;
    rep(j, Z){
        q.push(Elem(ab[0] + c[j], 0, j));
    }

    rep(_, K){
        ll cur;
        int i, j; tie(cur, i, j) = q.top();
        q.pop();

        cout << cur << endl;

        int ni = i + 1;
        if(ni < ab.size()){
            q.push(Elem(ab[ni] + c[j], ni, j));
        }
    }

    return 0;
}
