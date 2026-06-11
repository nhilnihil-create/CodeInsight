#include "bits/stdc++.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define LLINF (long long) 1e18//1234567890987654321
#define INF 1234567890ll
#define pb push_back
#define ins insert
#define f first
#define s second	
#define db 0
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos(-1))
#define MAXN (300006)
#define MAXK 26
#define MAXX 15000006
#define ll long long int 
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
#define FOR(ii, ss, ee) for(ll ii = ss; ii < ee; ii++)
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
ll n, q;
string A;
pair <char,char> Q[MAXN];
int main()
{
	FAST
	// freopen("10.in","r",stdin);
	// freopen("10.out","w",stdout);
	cin >> n >> q >> A;
	for(ll i=0;i<q;i++) cin>>Q[i].f>>Q[i].s;
	ll st = -1, en = n, mid = 0;
	while(en-st>1) {
		mid = (st+en)>>1;
		ll co = mid; bool can = 0;
		for(ll i=0;i<q;i++) {
			if(co >= n||co<0) break;
			if(Q[i].f == A[co]) {
				co -= (Q[i].s == 'L');
				co += (Q[i].s == 'R');
			}
		}
		if(co==-1) can = 1;
		if(can) st=mid;
		else en=mid;
	}
	ll tmp = st+1; // cerr << tmp << '\n';
	st = -1, en = n, mid = 0;
	while(en-st>1) {
		mid = (st+en)>>1ll;
		ll co = mid; bool can = 0;
		for(ll i=0;i<q;i++) {
			if(co >= n||co<0) break;
			if(Q[i].f == A[co]) {
				co -= (Q[i].s == 'L');
				co += (Q[i].s == 'R');
			}
		}
		if(co>=n) can = 1;
		if(can) en = mid;
		else st = mid;
	}
// 	cerr << en << '\n';
	ll out = tmp + (n-en);
	cout << n-out << '\n';
}