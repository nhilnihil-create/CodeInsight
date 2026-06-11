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

ll n, a[50];
 
int main(int argc, char **argv) {
	cin >> n;
	REP(i, n) cin >> a[i];
	ll mai = 0;
	REP(i, n) if (abs(a[i]) > abs(a[mai])) mai = i;
	cout << (2*n-2) << endl;
	REP(i, n) {
		if (i == mai) continue;
		a[i] += a[mai];
		cout << (mai + 1) << " " << (i+1) << endl;
	}
	if (a[mai] >= 0) REP(i, n-1) cout << (i+1) << " " << (i+2) << endl;
	else REPR(i, n-1) cout << (i+2) << " " << (i+1) << endl;
	return 0;
}
 