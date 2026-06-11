#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int L;
	cin >> L;

	vector<int> tapu;
	while (L > 0) {
		tapu.emplace_back(L % 2);
		L /= 2;
	}

	vector<tuple<int, int, int>> ans;
	vector<int> x(tapu.size(), 1);
	int sz = tapu.size();
	for (int i = 0; i + 1 < sz; ++i) {
		ans.emplace_back( i, i + 1, 0 );
		ans.emplace_back( i, i + 1, x[i] );
		x[i + 1] = x[i] * 2;
	}
	int X = 0;
	for (int i = sz - 1; i >= 0; --i) {
		if (tapu[i] == 0) { continue; }
		if (i < sz - 1) {
			ans.emplace_back( i, sz - 1, X );
		}
		X += x[i];
	}

	cout << tapu.size() << " " << ans.size() << endl;
	for (auto t : ans) {
		cout << get<0>(t) + 1 << " " << get<1>(t) + 1 << " " << get<2>(t) << endl;
	}

	return 0;
}
