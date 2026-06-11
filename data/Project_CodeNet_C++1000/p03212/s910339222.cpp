#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const ll INF = 1023456789;

#define REP(i,n)	for(int i=0;i<n;++i)
#define REPR(i,n)	for(int i=n-1;i>=0;--i)
#define FOR(i,s,n)	for(int i=s;i<n;++i)
#define FORR(i,s,n)	for(int i=n-1;i>=s;--i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define F			first
#define S			second

ll n, d;
ll s[10];
ll solve(ll i, ll l) {
	if (i < l) {
		ll res = 0;
		s[i] = 3;
		res += solve(i+1, l);
		s[i] = 5;
		res += solve(i+1, l);
		s[i] = 7;
		res += solve(i+1, l);
		return res;
	}
	bool f3 = false, f5 = false, f7 = false;
	REP(i, l) {
		f3 |= (s[i] == 3);
		f5 |= (s[i] == 5);
		f7 |= (s[i] == 7);
	}
	if (!f3 || !f5 || !f7) return 0;
	if (l < d) return 1;
	ll v = 0;
	REP(i, l) v = v*10 + s[i];
	return (v <= n ? 1 : 0);
}

int main(int argc, char **argv) {
	cin >> n;
	d = 0;
	for (ll i = n; i > 0; i /= 10) ++d;
	ll res = 0;
	FOR(i, 1, d+1) res += solve(0, i);
	cout << res << endl;
	return 0;
}
