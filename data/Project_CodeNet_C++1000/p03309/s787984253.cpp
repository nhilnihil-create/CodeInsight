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

ll n, a[200000];

ll calc(ll b) {
	ll res = 0;
	REP(i, n) res += abs(a[i] - b);
	return res;
}

ll solve(ll l, ll r) {
	if (l+3 >= r) return min(calc(l), min(calc(l+1), calc(l+2)));
	ll a = l+(r-l)/3, b = (a+r)/2;
	ll va = calc(a), vb = calc(b);
	if (va > vb) return solve(a, r);
	else return solve(l, b);
}

int main(int argc, char **argv) {
	cin >> n;
	REP(i, n) cin >> a[i];
	REP(i, n) a[i] -= i+1;
	cout << solve(-1000000001, 1000000001) << endl;
	return 0;
}
