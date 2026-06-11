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

void make_str(int n, string s) {
	if (n == 0) {
		if (bigger(s, s_cand)) {
			s_cand = s;
		}
		return;
	}

	for (auto p: nums) {
		if (n >= p.first) {
			make_str(n - p.first, s + p.second);
		}
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

	auto nums_head = nums[0];
	reverse(nums.begin(), nums.end());
	nums.pop_back();
	reverse(nums.begin(), nums.end());

	string ans;
	int n2 = n % nums_head.first;
	int n1 = n - n2;
	if (n2 == 0) {
		ans = string(n1 / nums_head.first, nums_head.second);
	} else {
		for (int i = 0; i < 20; i++) {
			s_cand.clear();
			make_str(n2, "");
			if (!s_cand.empty()) {
				string t = s_cand + string(n1 / nums_head.first, nums_head.second);
				sort(t.begin(), t.end(), greater<char>());
				if (bigger(t, ans)) {
					ans = t;
				}

			}
			// printf("i %2d: %s\n", i, s_cand.c_str());

			n1 -= nums_head.first;
			n2 += nums_head.first;

			if (n1 < 0) {
				break;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
