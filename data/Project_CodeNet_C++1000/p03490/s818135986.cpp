#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	string s; cin >> s;
	int gx, gy; cin >> gx >> gy;

	int xx, mode = 0, cnt = 0, spe = 1;
	vector<int>idx, idy;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == 'T' || i == s.size()) {
			if (spe)xx = cnt, spe = 0;
			else if (mode == 0)idx.push_back(cnt);
			else idy.push_back(cnt);
			mode ^= 1; cnt = 0;
		}
		else cnt++;
	}

	set<int>canX = { 0 }, canY = { 0 };
	for (auto&& sx : idx) {
		set<int>res(canX);
		canX.clear();
		for (auto&& x: res) {
			canX.insert(x + sx); canX.insert(x - sx);
		}
	}
	for (auto&& sy : idy) {
		set<int>res(canY);
		canY.clear();
		for (auto&& y: res) {
			canY.insert(y + sy); canY.insert(y - sy);
		}
	}
	cout << (canX.count(gx - xx) && canY.count(gy) ? "Yes" : "No") << endl;

	return 0;
}