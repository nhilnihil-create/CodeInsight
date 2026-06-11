#include "bits/stdc++.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define LLINF (long long) 1e18//1234567890987654321
#define INF 1234567890
#define pb push_back
#define ins insert
#define f first
#define s second	
#define db 0
#define EPS (1e-7)    //0.0000001 the value
#define PI (acos(-1))
#define MAXN 300006
#define MAXK 26
#define MAXX 15000006
#define ll long long int
#define ld long double
#define rep0(kk, l1, l2)for(ll kk = l1; kk < l2; kk++)
#define rep1(kk, l1, l2)for(ll kk = l1; kk <= l2; kk++)
#define foritr(itr, A) for(set<ll>::iterator itr = A.begin(); itr != A.end(); itr++)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
#define FOR(ii, ss, ee) for(ll ii = ss; ii < ee; ii++)
#define cr(x) cerr << #x << " = " << x << "\n";
#define crA(x, A) cerr << #x << " = " << A[x] << "\n";
#define spacing cout << " ";
#define mmst(x, v) memset((x), v, sizeof ((x)));
#define bg(ms) (*ms.begin())
#define ed(ms) (*prev(ms.end(), 1))
#define addedge(a, b, c, v) v[(a)].pb(pi((b), (c))); v[(b)].pb(pi((a), (c)))
#define ph push
#define btinpct(x) __builtin_popcountll(x)
#define p2(x) (1LL<<(x))
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
typedef pair <pi, pi> dpi;
inline ll rand(ll x, ll y) { ++y; return (rng() % (y-x)) + x; } //inclusivess
ll n, dist[MAXN];
vector <pi> v[MAXN];
int main()
{
	cin >> n;
	for(ll i = 0; i < n; i++) v[i].pb(pi((i+1)%n, 1));
	for(ll i = 0+1; i <= n; i++) v[i].pb(pi((i*10)%n, 0));
	mmst(dist, -1);
	dist[1] = 1;
	deque <ll> dq;
	dq.pb(1);
	while(!dq.empty())
	{
		ll x = dq.front();
		dq.pop_front();
		for(auto i : v[x])
		{
			ll to = i.f;
			if(dist[to] == -1||dist[to]>dist[x]+i.s)
			{
				dist[to] = dist[x] + i.s;
				if(i.s) dq.pb(i.f);
				else dq.push_front(i.f);
			}
		}
	}
	cout << dist[0] << "\n";
}