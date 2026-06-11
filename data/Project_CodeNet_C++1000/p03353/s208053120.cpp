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
 
int main(int argc, char **argv) {
	string s;
	ll k;
	cin >> s >> k;
	vector<string> a;
	REP(i, s.length()) FOR(j, 1, min(6, int(s.length()-i+1))) a.push_back(s.substr(i, j));
	sort(ALL(a));
	REP(i, a.size()) if (i == 0 || a[i] != a[i-1]) {
		--k;
		if (k == 0) {
			cout << a[i] << endl;
			break;
		}
	}
	return 0;
}
 