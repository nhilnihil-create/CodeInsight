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

ll n, x[100], y[100], h[100];

int main(int argc, char **argv) {
	cin >> n;
	REP(i, n) cin >> x[i] >> y[i] >> h[i];
	ll x1, y1, h1;
	REP(i, n) if (h[i] != 0) {
		x1 = x[i]; y1 = y[i]; h1 = h[i];
		break;
	}
	REP(cx, 101) REP(cy, 101) {
		ll ch = h1 + abs(x1 - cx) + abs(y1 - cy);
		bool ok = true;
		REP(i, n) ok &= (max((ll)0, ch - abs(x[i] - cx) - abs(y[i] - cy)) == h[i]);
		if (ok) {
			cout << cx << " " << cy << " " << ch << endl;
			return 0;
		}
	}
	return 0;
}
