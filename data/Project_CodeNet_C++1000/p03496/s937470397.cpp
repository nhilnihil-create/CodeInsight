#include <iostream>
#include <vector>
using namespace std;
const int INF = 1001001001;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> ans;
	int mina = INF, maxa = -INF, minidx, maxidx;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a < mina) {
			mina = a;
			minidx = i;
		}
		if (a > maxa) {
			maxa = a;
			maxidx = i;
		}
	}
	if (abs(maxa) > abs(mina)) {
		for (int i = 0; i < n; i++) {
			if (i == maxidx) continue;
			ans.emplace_back(maxidx, i);
		}
		for (int i = 0; i < n-1; i++) {
			ans.emplace_back(i, i+1);
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (i == minidx) continue;
			ans.emplace_back(minidx, i);
		}
		for (int i = n-1; i > 0; i--) {
			ans.emplace_back(i, i-1);
		}
	}
	cout << ans.size() << endl;
	for (auto e : ans) {
		cout << e.first+1 << ' ' << e.second+1 << endl;
	}
	return 0;
}