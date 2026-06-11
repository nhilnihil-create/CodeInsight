#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define ph push
#define f first
#define s second
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define btinpct(x) __builtin_popcountll((x))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?b:gcd(b%a,a); }

#define ll long long int 
#define ld long double
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
typedef pair <ll, ll> pi; typedef pair <ll, pi> spi; typedef pair <pi, pi> dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (300006)
ll n, k, q, A[2006], o[2006];
ll fw[2006];
void update(ll x,ll nval) {
	for(;x<=n;x+=x&(-x)) fw[x]+=nval;
}
void update(ll x,ll y,ll nval) {
	update(x, nval);
	update(y+1, -nval);
}
ll sum(ll x) { // point sum
	ll ox=x;
	ll res=0; for(;x;x-=x&(-x)) res+=fw[x]; return ox-res;
}
int main()
{
	FAST
	cin>>n>>k>>q;
	FOR(i,1,n) cin>>A[i];
	FOR(i,1,n) o[i]=i;
	sort(o+1, o+n+1, [](ll x,ll y){return A[x]<A[y];});
	set<int> s;s.ins(0);s.ins(n+1);
	function<ll(ll)> ppl=[&](ll x) {
		return sum(*s.lower_bound(x)) - sum(*prev(s.lower_bound(x))) - 1;
	};
	ll ans=LLINF;
	FOR(i,1,n) {
		mmst(fw, 0);
		if(ppl(o[i]) < k) continue; 
		ll mx = A[o[i]];
		ll have = 1;
		update(o[i]+1, n, 1);
		FOR(j,i+1,n) if(have < q && ppl(o[j]) >= k) {
			++ have, mx=A[o[j]];
			update(o[j]+1, n, 1); 
		}
		s.ins(o[i]);
		if(have >= q) ans=min(ans, mx-A[o[i]]);
	}
	cout<<ans<<'\n';
}
