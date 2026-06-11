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

ll c[3][3], a[3][3], b[3][3];
 
int main(int argc, char **argv) {
	REP(i, 3) REP(j, 3) cin >> c[i][j];
	REP(i, 3) REP(j, 3) a[i][j] = c[i][j] - c[0][j];
	REP(i, 3) REP(j, 3) b[i][j] = c[i][j] - c[i][0];
	cout << (a[1][0] == a[1][1] && a[1][1] == a[1][2]
		&& a[2][0] == a[2][1] && a[2][1] == a[2][2]
		&& b[0][1] == b[1][1] && b[1][1] == b[2][1]
		&& b[0][2] == b[1][2] && b[1][2] == b[2][2]
		? "Yes" : "No") << endl;
	return 0;
}
 