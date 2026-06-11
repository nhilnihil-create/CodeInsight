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

ll h, w;
char s[52][52];
 
int main(int argc, char **argv) {
	cin >> h >> w;
	REP(i, 52) REP(j, 52) s[i][j] = '.';
	REP(i, h) REP(j, w) cin >> s[i+1][j+1];
	REP(i, h) REP(j, w) if (s[i+1][j+1] == '#' && s[i][j+1] == '.' && s[i+2][j+1] == '.' && s[i+1][j] == '.' && s[i+1][j+2] == '.') {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}
 