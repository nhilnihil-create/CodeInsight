#include "bits/stdc++.h"

#define REP(i,n) for(int i=0;i< (n);i++)
#define REPR(i, n) for(int i = (n);i >= 0;i--)
#define FOR(i, m, n) for(int i = (m);i < (n);i++)
#define FORR(i, m, n) for(int i = (m);i >= (n);i--)
#define SORT(v, n) std::sort(v, v+n);
#define VSORT(v) std::sort(v.begin(), v.end());
#define VRSORT(v) std::sort(v.rbegin(), v.rend());
#define ll long long
#define pb(a) push_back(a)
#define ALL(obj) (obj).begin(),(obj).end()

using namespace std;

const int INF = 99999999;
const ll LINF = 9999999999999;

typedef pair<int, int> P;
typedef pair<ll, ll> LP;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


ll N,t[100000],x[100000],y[100000], tdiff[100000], xdiff[100000], ydiff[100000];
int main() {
	cin >> N;
	REP(i,N) {
		cin >> t[i] >> x[i] >> y[i];
	}

	tdiff[0] = t[0];
	xdiff[0] = x[0];
	ydiff[0] = y[0];

	for (int i = 1; i < N; i++) {
		tdiff[i] = t[i] - t[i - 1];
		xdiff[i] = abs(x[i] - x[i - 1]);
		ydiff[i] = abs(y[i] - y[i - 1]);
	}

	string answer = "Yes";
	REP(i, N) {
		if (xdiff[i] + ydiff[i] > tdiff[i] || (tdiff[i] - (xdiff[i] + ydiff[i])) % 2 == 1) answer = "No";
	}

	cout << answer << endl;

	return 0;
}