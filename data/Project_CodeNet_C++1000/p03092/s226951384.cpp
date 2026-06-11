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
#define MAXN (5006)
ll n, a, b, A[MAXN], dp[2][MAXN], pos[MAXN], co[MAXN]; // dp(i, j) = dp(val i, at pos j -> 0 all the elements are in order);
int main()
{ // can be proven that each element moves once
	FAST
	cin>>n>>a>>b;
	FOR(i,1,n)cin>>A[i],pos[A[i]]=i;
	FOR(i,1,n) {
		mmst(dp[i%2],0);
		ll x=pos[i];
		FOR(j,1,x-1) dp[i%2][j]=dp[i%2^1][j]; // storing history values (won't be changed), but might be referenced in the future
		FOR(j,x,n){ // legit ones
			dp[i%2][j]=min((j==x?LLINF:dp[i%2^1][j]+a), dp[i%2^1][x-1] + b * (co[j] - co[x])); // move all blocking elements to correct position, u'll end up at position i (cos i-p-1 items just got moved)
		}
		FOR(i,x,n) ++ co[i];
		// FOR(j,1,n)cerr<<dp[i%2][j]<<' '; cerr<<'\n';
	}
	cout<<dp[n%2][n]<<'\n';
}
