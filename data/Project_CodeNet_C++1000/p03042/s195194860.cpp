#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define dump(x)  cout << #x << " = " << (x) << endl;	//debug
#define SZ(x) ((int)(x).size())
#define REP(i, n) for(ll i = 0; i < (n); i++)
#define REPR(i, n) for (ll i = (n); i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, l, r)  (a).begin()+(l),(a).begin()+(r)


int main() {
	string s;
	cin >> s;
	bool isformm = false;
	if (s[0] == '0') {
		if (s[1] != '0') {
			isformm = true;
		}
	}
	else if (s[0] == '1') {
		if (s[1] == '1' || s[1] == '2') {
			isformm = true;
		}
	}

	bool islatmm = false;
	if (s[2] == '0') {
		if (s[3] != '0') {
			islatmm = true;
		}
	}
	else if (s[2] == '1') {
		if (s[3] == '1' || s[3] == '2') {
			islatmm = true;
		}
	}
	
	if (isformm && islatmm) {
		ps(AMBIGUOUS)
	}
	else if (isformm) {
		ps(MMYY);
	}
	else if (islatmm) {
		ps(YYMM);
	}
	else {
		ps(NA);
	}
	return(0);
}