#include <bits/stdc++.h>
using namespace std;

using ll = long long;

set<int> solve() {
	int N; cin >> N;
	if (N == 3) return set<int>{2, 5, 63};
	if (N == 4) return set<int>{2, 5, 20, 63};
	set<int> res;
	for (int i = 1; i <= 30000; i++) {
		if (i % 6 != 1 && i % 6 != 5) res.insert(i);
	}
	vector<int> mi{6, 1, 2, 3, 4, 5};
	N = 20000 - N;
	for (int i = 1; i < N; i+=2) {
		if (i / 2 % 4 == 0) {
			res.erase(mi[0]); res.erase(mi[0]+6);
			mi[0] += 12;
		} else if (i / 2 % 4 < 3) {
			res.erase(mi[2]); res.erase(mi[4]);
			mi[2] += 6; mi[4] += 6;
		} else {
			res.erase(mi[3]); res.erase(mi[3]+6);
			mi[3] += 12;
		}
	}
	if (N & 1) res.erase(mi[0]);
	if (N == 20000 - 5) { res.insert(6); res.erase(mi[2]); res.erase(mi[4]);}
	return res;
}

int main() {
	auto res = solve();
	for (auto x : res) cout << x << endl;
}