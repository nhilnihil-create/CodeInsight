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

ll n, m, p[100000], y[100000];
vector<P> a[100000];
string res[100000];

int main(int argc, char **argv) {
	cin >> n >> m;
	REP(i, m) {
		cin >> p[i] >> y[i];
		--p[i];
		a[p[i]].push_back(P{y[i], i});
	}
	char t[13];
	REP(i, n) {
		sort(ALL(a[i]));
		REP(j, a[i].size()) {
			sprintf(t, "%06d%06d", i+1, j+1);
			res[a[i][j].S] = string(t);
		}
	}
	REP(i, m) cout << res[i] << endl;
	return 0;
}
