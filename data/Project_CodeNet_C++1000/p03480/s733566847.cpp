#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define testing 1
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
#define IAMSPEED ios_base::sync_with_stdio(false); cin.tie(0);
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << " , " << #y << "=" << y << endl
#define db3(a,b,c) cerr<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c<<endl
#define dbv(v) cerr << #v << ":"; for (auto it : v) cerr << it << ' '; cerr << endl
#define dbvp(v) cerr << #v << ":"; for (auto it : v) cerr << "{"  << it.f << ',' << it.s << "} "; cerr << endl
#define dba(a,ss,ee) cerr << #a << ":"; FOR(i,ss,ee) cerr << a[i] << ' '; cerr << endl
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define ll long long 
#define pb push_back
#define inf (int)1e9+500
#define oo (ll)1e18+500
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define reach cerr << "hi\n";
typedef pair <int, int> pi;
typedef pair <ll,ll> pl;
typedef pair <pi, int> pii;
typedef tuple<int,int,int> ti3;
string cts(char x) {string s(1,x); return s;}
const int MOD = 1e9 + 7;
template <typename T> void maxself(T& a, T b) {
	a = max(a, b);
}
template <typename T> void minself(T& a, T b) {
	a = min(a, b);
}
#define MAXN
#if !testing
#define cerr if(0)cout
#endif
int32_t main() {
	IAMSPEED
	string str; cin >> str;
	int n = str.size();
	ll ans = n;
	str = "A" + str;
	FOR(i,1,n) {
		if(str[i]!=str[i+1]) {
			minself(ans,max(i,n-i));
		}
	}
	cout<<ans;
}
