#include "bits/stdc++.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
#define pb push_back
#define eb emplace_back
#define ins insert
#define f first
#define s second	
#define db 0
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos(-1))
#define MAXN (300006)
#define ll long long int 
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
#define FOR(ii, ss, ee) for(ll ii = ss; ii < ee; ++ii)
#define space " "
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define ph push
#define emp emplace
#define btinpct(x) __builtin_popcountll(x)
#define p2(x) (1LL<<(x))
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
typedef pair <pi, pi> dpi;
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss
ll n,A[MAXN],sum[MAXN];
const ll MOD=1e9+7;
ll qexp(ll x, ll e){
	if(e==0)return 1;
	ll half=qexp(x,e/2);
	half*=half;
	half%=MOD;
	if(e&1)half*=x,half%=MOD;
	return half;
}
ll mul_inv(ll x) { return qexp(x,MOD-2); }
int main()
{
	FAST
	cin>>n;
	FOR(i,0,n)cin>>A[i];
	sum[1]=0;
	FOR(i,2,n+5){
		sum[i]=sum[i-1]+mul_inv(i);sum[i]%=MOD;
	}
	ll ans=0;
	FOR(i,0,n){
		ans+=sum[i+1]*A[i]%MOD;ans%=MOD;
		ans+=sum[n-i]*A[i]%MOD;ans%=MOD;
		ans+=A[i];ans%=MOD;
	}
	ll f=1;
	FOR(i,2,n+1)f*=i,f%=MOD;
	ans*=f;ans%=MOD;
	cout<<ans;
}
