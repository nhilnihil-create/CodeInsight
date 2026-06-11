#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	unordered_map<int, int> um1;
	unordered_map<int, unordered_map<int, int>> um2;
	vector<pair<int, int>> vp;
	for (int i = 0; i < m; i++) {
		int p, y;
		cin >> p >> y;
		vp.push_back(make_pair(p, y));
	}
	vector<pair<int, int>> vp_ = vp;
	sort(vp_.begin(), vp_.end());
	for (auto p : vp_) {
		um1[p.first]++;
		um2[p.first][p.second] = um1[p.first];
	}
	for (int i = 0; i < m; i++) {
		string s1 = to_string(vp[i].first);
		string s2 = to_string(um2[vp[i].first][vp[i].second]);
		s1 = string(6 - s1.size(), '0') + s1;
		s2 = string(6 - s2.size(), '0') + s2;
		cout << s1 << s2 << endl;
	}
}
