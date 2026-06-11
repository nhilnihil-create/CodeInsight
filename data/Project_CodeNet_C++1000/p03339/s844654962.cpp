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

ll n, w[300001], e[300001];
string s;
 
int main(int argc, char **argv) {
	cin >> n >> s;
	w[0] = e[0] = 0;
	REP(i, n) {
		bool f = (s[i] == 'W');
		w[i+1] = w[i] + (f ? 1 : 0);
		e[i+1] = e[i] + (f ? 0 : 1);
	}
	ll res = n;
	REP(i, n) res = min(res, w[i]-w[0] + e[n]-e[i+1]);
	cout << res << endl;
	return 0;
}
 