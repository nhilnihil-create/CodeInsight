#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <map>

using namespace std;
using PIC = pair<int, char>;

const vector<int> num_match = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

vector<PIC> nums;
string s_cand;

bool bigger(const string &s, const string &t) {
	if (s.size() == t.size()) {
		return s > t;
	} else {
		return s.size() > t.size();
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> a(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	map<int, int> tmp;
	for (auto x: a) {
		tmp[num_match[x]] = x;
	}
	for (auto p: tmp) {
		nums.emplace_back(p.first, '0' + p.second);
	}
	sort(nums.begin(), nums.end(),
		[](PIC &a, PIC &b) {
			return a.second < b.second;
		});

	vector<string> dp(n + 1, "0");
	dp[0] = "";

	for (int i = 0; i < n; i++) {
		if (dp[i] == "0") {
			continue;
		}
		for (auto p: nums) {
			int ni = i + p.first;
			string s = dp[i] + p.second;

			if (ni <= n && bigger(s, dp[ni])) {
				dp[ni] = s;
			}
		}
	}

	cout << dp[n] << endl;
	return 0;
}
