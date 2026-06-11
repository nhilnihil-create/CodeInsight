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

int n, a[100], b[100], c[100], d[100];
vector<int> es[200];
bool used[200];
int match[200];

bool dfs(int v) {
	used[v] = true;
	REP(i, es[v].size()) {
		int t = es[v][i];
		int m = match[t];
		if (m < 0 || (!used[m] && dfs(m))) {
			match[v] = t;
			match[t] = v;
			return true;
		}
	}
	return false;
}

int flow() {
	int f = 0;
	memset(match, -1, sizeof(match));
	REP(i, n*2) if (match[i] < 0) {
		memset(used, 0, sizeof(used));
		if (dfs(i)) ++f;
	}
	return f;
}
 
int main(int argc, char **argv) {
	cin >> n;
	REP(i, n) cin >> a[i] >> b[i];
	REP(i, n) cin >> c[i] >> d[i];
	REP(i, n) REP(j, n) if (a[i] < c[j] && b[i] < d[j]) {
		es[i].push_back(n+j);
		es[n+j].push_back(i);
	}
	cout << flow() << endl;
	return 0;
}
 