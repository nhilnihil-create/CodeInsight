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

ll n, a[3], l[8];
ll d[8];

ll solve(ll i) {
	if (i >= n) {
		vector<ll> b[3];
		REP(j, n) if (d[j] >= 0) b[d[j]].push_back(j);
		REP(j, 3) if (b[j].size() == 0) return INF;
		ll res = 0;
		REP(j, 3) {
			res += (b[j].size() - 1) * 10;
			ll s = 0;
			REP(k, b[j].size()) s += l[b[j][k]];
			res += abs(s - a[j]);
		}
		return res;
	} else {
		ll res = INF;
		REP(j, 4) {
			d[i] = j-1;
			res = min(res, solve(i+1));
		}
		return res;
	}
}

int main(int argc, char **argv) {
	cin >> n;
	REP(i, 3) cin >> a[i];
	REP(i, n) cin >> l[i];
	cout << solve(0) << endl;
	return 0;
}
