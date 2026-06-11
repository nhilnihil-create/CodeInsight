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

// 00000000-00000001 [  0,   1] [  0,   1]
// 00000010-00000011 [ -2,  -1] [ -2,   1]
// 00000100-00000111 [  2,   5] [ -2,   5]
// 00001000-00001111 [-10,  -3] [-10,   5]
// 00010000-00011111 [  6,  21] [-10,  21]
// 00100000-00111111 [-42, -11] [-42,  21]
// 01000000-01111111 [ 22,  85] [-42,  85]
// 10000000-11111111 [-170,-43] [-170, 85]

void solve(ll n, ll b) {
	ll c, m, v;
	if (n == 0) {
		REP(i, b+1) cout << "0";
		return;
	}
	if (n > 0) {
		m = (n+2)/4;
		c = 0;
		v = 1;
	} else {
		m = ((-n+1)/2+2)/4;
		c = 1;
		v = -2;
	}
	for (; m > 0; m = (m+2)/4, c += 2, v *= 4);
	REP(i, b-c) cout << "0";
	cout << "1";
	solve(n-v, c-1);
}

int main(int argc, char **argv) {
	ll n;
	cin >> n;
	solve(n, 0);
	cout << endl;
	return 0;
}
