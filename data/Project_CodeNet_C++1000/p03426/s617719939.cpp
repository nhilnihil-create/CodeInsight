#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;
using PII = pair<int, int>;

int main() {
	int h, w, d, tmp;
	cin >> h >> w >> d;

	vector<vector<int>> a(h, vector<int>(w, 0));
	vector<PII> val2point(h * w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> tmp;
			tmp--;
			val2point[tmp] = make_pair(i, j);
			a[i][j] = tmp;
		}
	}

	vector<long long> cumul(h * w, -1);
	for (int st = 0; st < d; st++) {
		cumul[st] = 0;

		for (int i = st; i + d < cumul.size(); i += d) {
			auto from = val2point[i];
			auto to = val2point[i + d];

			cumul[i + d] = cumul[i] + abs(to.first - from.first) + abs(to.second - from.second);
		}
	}

	int q, l, r;
	cin >> q;
	vector<long long> ans(q);
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		l--;
		r--;
		ans[i] = cumul[r] - cumul[l];
	}

	for (auto x: ans) {
		cout << x << endl;
	}


	return 0;
}
