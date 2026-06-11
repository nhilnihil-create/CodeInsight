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
#define siz(x) ll(x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?llabs(b):gcd(b%a,a); }

typedef long long ll; 
typedef long double ld;
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
typedef pair<ll,ll>pi; typedef pair<ll,pi>spi; typedef pair<pi,pi>dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (300006)
ll n;
ll A[MAXN];
int main()
{
	FAST
	cin>>n;
	bool gotneg=0, gotpos=0;
	FOR(i,0,n-1)cin>>A[i], gotneg|=(A[i]<0), gotpos|=(A[i]>0);
	if(gotneg==0) {
		cout<<n-1<<'\n';
		FOR(i,0,n-2) {
			cout<<i+1<<' '<<i+2<<'\n';
		}
		return 0;
	}
	if(gotpos==0) {
		cout<<n-1<<'\n';
		DEC(i,n-1,1) {
			cout<<i+1<<' '<<i<<'\n';
		}
		return 0;
	}
	ll mx=max_element(A,A+n)-A, mi=min_element(A,A+n)-A;
	if(A[mx]>-A[mi]) {
		ll co = 0;
		FOR(i,0,n-1) co += (A[i]<0);
		cout<<co+n-1<<'\n';
		FOR(i,0,n-1) if(A[i]<0) cout<<mx+1<<' '<<i+1<<'\n';
		FOR(i,0,n-2) {
			cout<<i+1<<' '<<i+2<<'\n';
		}
	} else {
		ll co = 0;
		FOR(i,0,n-1) co += (A[i]>0);
		cout<<co+n-1<<'\n';
		FOR(i,0,n-1) if(A[i]>0) cout<<mi+1<<' '<<i+1<<'\n';
		DEC(i,n-1,1) {
			cout<<i+1<<' '<<i<<'\n';
		}
	}
}
