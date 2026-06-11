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

ll n, m, t[400001];

ll gcd(ll a, ll b) {
	if (b > a) return gcd(b, a);
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

ll q(ll a, ll b, ll k, ll l, ll r) {
	if (r <= a || b <= l) return 0;
	if (a <= l && r <= b) return t[k];
	ll vl = q(a, b, k*2+1, l, (l+r)/2);
	ll vr = q(a, b, k*2+2, (l+r)/2, r);
	if (vl == 0) return vr;
	if (vr == 0) return vl;
	return gcd(vl, vr);
}

int main(int argc, char **argv) {
	cin >> n;
	for (m = 1; m < n; m *= 2);
	REP(i, n) cin >> t[m-1+i];
	FOR(i, n, m) t[m-1+i] = t[m+n-2];
	REPR(i, m-1) t[i] = gcd(t[i*2+1], t[i*2+2]);
	ll res = 1;
	REP(i, n) {
		if (i == 0) res = max(res, q(i+1, n, 0, 0, m));
		else if (i == n-1) res = max(res, q(0, i, 0, 0, m));
		else res = max(res, gcd(q(0, i, 0, 0, m), q(i+1, n, 0, 0, m)));
	}
	cout << res << endl;
	return 0;
}
