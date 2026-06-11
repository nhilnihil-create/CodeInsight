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
const ll INFL = 1223372036854775807;
const ll mod = 1000000007;		








int main() {
	
	int n;
	cin >> n;

	VI d(13, 0);
	d[0]++;

	REP(i, n) {
		int a;
		cin >> a;
		d[a]++;
	}

	if (d[0] != 1 || d[12] > 1) {
		cout << 0 << endl;
		return 0;
	}
	REP(i, 13) {
		if (d[i] >= 3) {
			cout << 0 << endl;
			return 0;
		}
	}

	VI v;
	VI x;
	v.push_back(0);
	if (d[12] == 1)v.push_back(12);

	FOR(i, 1, 12) {
		if (d[i] == 2) {
			v.push_back(i);
			v.push_back(24 - i);
		}
		else if (d[i] == 1)x.push_back(i);
	}

	int ans = 0;


	REP(i, (1 << x.size()) + 1) {
		
		VI y = v;
		REP(j, x.size()) {
			if (i & (1 << j))y.push_back(x[j]);
			else y.push_back(24 - x[j]);
		}

		sort(ALL(y));
		y.push_back(24);
		int res = 24;
		REP(i, y.size() - 1)res = min(res, y[i + 1] - y[i]);
		ans = max(ans, res);
	}

	cout << ans << endl;

	return 0;

}