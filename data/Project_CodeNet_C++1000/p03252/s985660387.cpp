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

string s, t;
int p[256], q[256];

int main(int argc, char **argv) {
	cin >> s >> t;
	memset(p, -1, sizeof(p));
	memset(q, -1, sizeof(q));
	REP(i, s.length()) {
		if (p[s[i]] != q[t[i]]) {
			cout << "No" << endl;
			return 0;
		}
		p[s[i]] = i;
		q[t[i]] = i;
	}
	cout << "Yes" << endl;
	return 0;
}
