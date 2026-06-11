//marico el que lo lea
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

void fastIO() {std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

#define pb push_back
#define all(obj) obj.begin(), obj.end()
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ms2(obj, val, sz) memset(obj, val, sizeof(obj[0])*sz)

#define fst first
#define snd second

template<typename T, typename U> inline void mnze(T &x, U y) {if(y < x) x = y;}
template<typename T, typename U> inline void mxze(T &x, U y) {if(x < y) x = y;}

void _scan( int &x ) { scanf("%d",&x); }
void _scan( long long &x ) { scanf("%lld",&x); }
void _scan( double &x ) { scanf("%lf",&x); }
void _scan( char &x ) { scanf(" %c",&x); }
void _scan( char *x ) { scanf("%s",x); }
template<typename T>
void _scan( vector<T> &v ){
	for(int i=0; i<(int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template<typename T, typename... U>
void scan( T& head, U&... tail ) { _scan(head); scan(tail...);}

template<typename T> void _dbg(const char* sdbg, T h)
	{ cerr<<sdbg<<"="<<h<<"\n"; }
template<typename T, typename... U> void _dbg(const char* sdbg, T h, U... t) {
	while(*sdbg != ',')cerr<<*sdbg++;
	cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr<<#x<<" = "; for(auto _i:x) cerr<<_i<<", ";cerr<<"\n";}}
#define debuga(x, sz) {{cerr<<#x<<" = ";for(int _i=0;_i<sz;_i++)cerr<<x[_i]<<", ";cerr<<"\n";}}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define debuga(x, sz)
#define cerr if(0)cout
#endif

ll MOD = 1e9+7;

inline ll Msum(ll x){return x;}
template<typename... Rest>
inline ll Msum(ll x, Rest... rest){ return (x + Msum(rest...)) % MOD; }

inline ll Mprod(ll x){return x;}
template<typename... Rest>
inline ll Mprod(ll x, Rest... rest){ return x * Mprod(rest...) % MOD; }

inline ll Mnorm(ll x){ return (x%MOD + MOD) %MOD; }

struct BIT{
    int N, MAXLOG;
    vll a;
    void init(int n){
		ll pot = 1, k=0;
		while(pot < n) pot*=2, k++;
        a.resize(pot+2);
        N = pot; MAXLOG = k-1;
    }
	void clean(){
		for(int i=0; i<(int)a.size(); i++) a[i] = 0;
	}
    void upd(int p, ll val){
        for(++p; p <= N; p += p & -p)
            a[p] += val;
    }

    // sum[0,p]
    ll sum(int p){
        ll ret = 0;
        for(++p; p; p -= p & -p)
            ret += a[p];
        return ret;
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

const int MAXN = 1e5+5;
int n;
int a[MAXN];

BIT bit;
ll check(int mi){
	bit.clean();

	ll ret = 0;
	ll cur=0;
	bit.upd(n+cur, 1);
	for(int i=0; i<n; i++){
		int x;
		if(a[i] <= mi) x=1;
		else if(a[i] > mi) x=-1;

		cur += x;
		//cur - pref >= 1
		//pref <= cur-1
		ret += bit.sum(cur-1+n);
		bit.upd(n+cur, 1);
	}
	return ret;
}

int solve(){
	bit.init(2*n+5);

	ll X = 1LL*n*(n+1)/2;
	ll M = (X/2)+1;

	//debug(X, M);

	int lo=0, hi=n-1;
	while(lo < hi){
		//debug(lo, hi);
		int mi=(lo+hi)/2;
		//debug(mi, check(mi));
		if(check(mi) < M) lo=mi+1;
		else hi=mi;
	}
	return lo;
}

int main(){
	scan(n);
	vector<ii> cmp;
	for(int i=0; i<n; i++){
		scan(a[i]);
		cmp.pb({a[i], i});
	}
	sort(all(cmp));
	for(int i=0; i<n; i++)
		a[i] = distance(cmp.begin(), lower_bound(all(cmp), make_pair(a[i], i)));
	int ans = solve();
	printf("%d\n", cmp[ans].fst);
}
