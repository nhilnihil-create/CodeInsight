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
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

const int MAXN = 2e5+5;

int n;
ll a[MAXN], aa[MAXN];

ll sum(int i, int j){
	return aa[j]-aa[i]+a[i];
}

int split(int L, int R){
	int lo=L, hi=R-1;
	while(lo < hi){
		int mi = (lo+hi+1)/2;
		if(sum(L, mi) <= sum(mi+1, R)) lo=mi;
		else hi=mi-1;
	}
	return max(L, lo);
}

int main(){
	scan(n);
	for(int i=0; i<n; i++) scan(a[i]);
	aa[0] = a[0];
	for(int i=1; i<n; i++) aa[i] = aa[i-1] + a[i];

	ll ans = 1e18;
	for(int B=1; B<n-1; B++){
		int A = split(0, B);
		int C = split(B+1, n-1);
		vector<pair<ll, ll>> opa, opc;

		ll s1, s2;
		s1 = sum(0, A), s2 = sum(A+1, B);
		opa.pb({min(s1, s2), max(s1, s2)});
		if(A+1<B){
			A++;
			s1 = sum(0, A), s2 = sum(A+1, B);
			opa.pb({min(s1, s2), max(s1, s2)});
		}

		s1 = sum(B+1, C), s2 = sum(C+1, n-1);
		opc.pb({min(s1, s2), max(s1, s2)});
		if(C+1 < n-1){
			C++;
			s1 = sum(B+1, C), s2 = sum(C+1, n-1);
			opc.pb({min(s1, s2), max(s1, s2)});
		}
		for(auto a : opa) for(auto b : opc){
			mnze(ans, max(a.snd, b.snd) - min(a.fst, b.fst));
		}
	}
	printf("%lld\n", ans);
}
