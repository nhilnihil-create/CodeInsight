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

ll d, g, p[10], c[10], s[10];

int main(int argc, char **argv) {
	cin >> d >> g;
	REP(i, d) cin >> p[i] >> c[i];
	REP(i, d) s[i] = (d-i)*100;
	reverse(p, p+d);
	reverse(c, c+d);
	ll res = INF;
	REP(i, 1<<d) {
		ll v = 0, cnt = 0;
		REP(j, d) if (i & (1<<j)) {
			v += s[j]*p[j] + c[j];
			cnt += p[j];
		}
		if (v < g) REP(j, d) if ((i & (1<<j)) == 0) {
			ll t = min(p[j], (g-v+s[j]-1)/s[j]);
			cnt += t;
			v += s[j]*t;
			break;
		}
		if (v >= g) res = min(res, cnt);
	}
	cout << res << endl;
	return 0;
}
