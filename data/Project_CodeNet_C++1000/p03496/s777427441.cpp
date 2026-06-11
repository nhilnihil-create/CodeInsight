
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main() {
	int n;
	vector<int> a;
	int minval = 10000000;
	int maxval = -10000000;
	int maxvalpos = 0;
	int minvalpos = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int ai;
		cin >> ai;
		if (minval > ai) {
			minval = ai;
			minvalpos = i;
		}
		if (maxval < ai) {
			maxval = ai;
			maxvalpos = i;
		}
		a.push_back(ai);
	}

	vector<pair<int, int>> res;
	if (abs(maxval) > abs(minval)) {
		for (int i = 0; i < n; ++i) {
			res.push_back(make_pair(maxvalpos, i));
		}
		for (int i = 0; i + 1 < n; ++i) {
			res.push_back(make_pair(i, i+1));
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			res.push_back(make_pair(minvalpos, i));
		}
		for (int i = n-1; i-1>=0 ; --i) {
			res.push_back(make_pair(i, i-1));
		}
	}
	cout << res.size() << endl;
	for (auto val : res) {
		cout << val.first + 1 << " " << val.second + 1 << endl;
	}
	return 0;
}