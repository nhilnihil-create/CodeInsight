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

ll n;
P x[200000];
ll r[200000];
 
int main(int argc, char **argv) {
	cin >> n;
	REP(i, n) {
		x[i].S = i;
		cin >> x[i].F;
	}
	sort(x, x+n);
	REP(i, n) r[x[i].S] = i;
	REP(i, n) cout << (r[i] >= n/2 ? x[n/2-1].F : x[n/2].F) << endl;
	return 0;
}
 