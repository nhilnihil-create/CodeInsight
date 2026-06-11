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

ll n, c;
vector<P> st[30], st2;
 
int main(int argc, char **argv) {
	cin >> n >> c;
	REP(i, n) {
		ll ts, tt, tc;
		cin >> ts >> tt >> tc;
		--tc;
		st[tc].push_back(P{ts, tt});
	}
	REP(i, c) sort(ALL(st[i]));
	REP(i, c) {
		if (st[i].size() == 0) continue;
		ll l = st[i][0].F;
		REP(j, st[i].size()-1) if (st[i][j].S < st[i][j+1].F) {
			st2.push_back(P(l, -1));
			st2.push_back(P(st[i][j].S, 1));
			l = st[i][j+1].F;
		}
		st2.push_back(P{l, -1});
		st2.push_back(P{st[i][st[i].size()-1].S, 1});
	}
	sort(ALL(st2));
	ll res = 0, cnt = 0;
	REP(i, st2.size()) {
		cnt -= st2[i].S;
		res = max(res, cnt);
	}
	cout << res << endl;
	return 0;
}
 