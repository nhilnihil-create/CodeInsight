#include "bits/stdc++.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
#define pb push_back
#define ins insert
#define f first
#define s second	
#define db 0
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos(-1))
#define MAXN (300006)/3
#define MAXK 26
#define MAXX 15000006
#define ll long long int 
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
#define FOR(ii, ss, ee) for(ll ii = ss; ii < ee; ++ii)
#define space " "
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define ph push
#define btinpct(x) __builtin_popcountll(x)
#define p2(x) (1LL<<(x))
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
typedef pair <pi, pi> dpi;
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivesss
ll n,a,b,A[5002],dp[5002], prev_dp[5002], at[5002], co[5002];

int main()
{
	FAST
	cin>>n>>a>>b;
	for(ll i=1;i<=n;++i){cin>>A[i];at[A[i]]=i;}
	FOR(k,1,n+1) {
		mmst(dp,0);
		ll p = at[k];
		for(ll i=1;i<p;i++)  dp[i] = prev_dp[i];
		for(ll i=p;i<=n;i++) {
			dp[i] = min((i==p?LLINF:prev_dp[i]+a), prev_dp[p-1] + b * (co[i] - co[p]));
		}
		for(ll i=p;i<=n;i++) co[i] += 1;
		swap(dp,prev_dp);
	}
	cout<<prev_dp[n]<<'\n';
}
