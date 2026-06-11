#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	string s; cin >> s;
	int gx, gy; cin >> gx >> gy;

	int xx, mode = 0, count = 0, tokubetu = 1;
	vector<int> idox, idoy;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == 'T' || i == s.size()) {
			if (tokubetu) xx = count, tokubetu = 0;
			else if (mode == 0) idox.push_back(count);
			else idoy.push_back(count);
			mode ^= 1;
			count = 0;
		}
		else {
			count++;
		}
	}

	set<int> cangox = { 0 }, cangoy = { 0 };
	for (auto sa : idox) {
		set<int> res(cangox);
		cangox.clear();
		for (auto x : res) {
			cangox.insert(x + sa);
			cangox.insert(x - sa);
		}
	}

	for (auto sa : idoy) {
		set<int> res(cangoy);
		cangoy.clear();
		for (auto y : res) {
			cangoy.insert(y + sa);
			cangoy.insert(y - sa);
		}
	}

	if (cangox.count(gx - xx) && cangoy.count(gy)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}