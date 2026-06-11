#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define fore(i,a) for(auto &i:a)

typedef pair <int, int> P;
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
const int  INF = 1 << 30;
const ll INFL = 1LL<<60;
const ll mod = 1000000007;		




int main() {

	int n;
	cin >> n;
	VI a(n);
	REP(i, n)cin >> a[i];

	int ma = -INF, mi = INF, itma, itmi;

	REP(i, n) {
		if (ma < a[i]) {
			itma = i;
			ma = a[i];
		}
		if (mi > a[i]) {
			itmi = i;
			mi = a[i];
		}
	}

	cout << 2 * n - 1 << endl;

	if (abs(ma) > abs(mi)) {
		REP(i, n) {
			cout << itma + 1 << ' ' << i+1 << endl;
			a[i] += a[itma];
		}
		REP(i, n - 1) {
			cout << i+1 << ' ' << i+2 << endl;
			a[i + 1] += a[i];
		}
	}
	else {
		REP(i, n) {
			cout << itmi + 1 << ' ' << i+1 << endl;
			a[i] += a[itmi];
		}
		for (int i = n - 1; i >= 1; i--) {
			cout << i + 1 << ' ' << i << endl;
			a[i - 1] += a[i];
		}
	}

}