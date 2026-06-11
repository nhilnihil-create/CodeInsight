#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<vector>
using namespace std;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//infinity
#define INTINF 2000000000
#define LONGINF 2000000000

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

int main(){
	int n; cin >> n;
	int N = n + 2;
	long long c; cin >> c;
	long long x[N], v[N];
	long long lx[N], lc[N], rx[N], rc[N];
	long long ml[N], mr[N];
	FOR(i, 1, N - 1) cin >> x[i] >> v[i];
	x[0] = v[0] = lx[0] = lc[0] = rx[0] = rc[0] = ml[0] = mr[0] = 0;
	x[N-1] = v[N-1] = lx[N-1] = lc[N-1] = rx[N-1] = rc[N-1] = ml[N-1] = mr[N-1] = 0;
 
	long long ans = 0;
	FOR(i, 1, N - 1){
		lx[i] = x[i]; lc[i] = lc[i-1] + v[i];
		long long t = lc[i] - lx[i];
		ans = max(ans, t);
		ml[i] = max(ml[i-1], t);
	}
 
	for(int i = N-2; i > 0; i--){
		rx[i] = c - x[i]; rc[i] = rc[i+1] + v[i];
		long long t = rc[i] - rx[i];
		ans = max(ans, t);
		mr[i] = max(mr[i+1], t);
	}
 
	FOR(i, 1, N - 1){
		long long l = lc[i] - 2 * lx[i];
		long long r = mr[i+1];
		ans = max(ans, l + r);
	}

	for(int i = N-2; i > 0; i--){
		long long l = ml[i-1];
		long long r = rc[i] - 2 * rx[i];
		ans = max(ans, l + r);
	}

	cout << ans << endl;
	return 0;
}

