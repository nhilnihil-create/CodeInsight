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
const int inf = 1e6;

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

	vector<int> dp(n + 1, -inf);
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		if (dp[i] == -inf) {
			continue;
		}
		for (auto p: nums) {
			int ni = i + p.first;
			if (ni <= n) {
				dp[ni] = max(dp[ni], dp[i] + 1);
			}
		}
	}

	sort(nums.begin(), nums.end(),
		[](PIC &a, PIC &b) {
			return a.second > b.second;
		});

	string ans;
	int idx = n;
	while (ans.size() < dp[n]) {
		for (auto p: nums) {
			int ni = idx - p.first;
			if (ni >= 0 && dp[ni] == dp[idx] - 1) {
				ans += p.second;
				idx = ni;
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
