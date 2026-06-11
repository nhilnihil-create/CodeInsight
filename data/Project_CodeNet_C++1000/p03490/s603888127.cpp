#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s; cin >> s; s += "T";
	int x, y; cin >> x >> y;

	int t = 0;
	int d = 0;
	bool first = true;
	vector<vector<int>> v(2);
	rep(i, 0, s.size()) {
		if (s[i] == 'T') {
			if (t) {
				if (first)
					x -= t;
				else
					v[d].push_back(t);
				t = 0;
			}
			d ^= 1;
			first = false;
		}
		else
			t++;
	}
	vector<set<int>> st(2);

	rep(i, 0, 2) {
		st[i].insert(0);
		for (auto x : v[i]) {
			set<int> nst;
			for (auto y : st[i]) {
				nst.insert(y + x);
				nst.insert(y - x);
			}
			st[i] = nst;
		}
	}
	if (st[0].count(x) && st[1].count(y)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}