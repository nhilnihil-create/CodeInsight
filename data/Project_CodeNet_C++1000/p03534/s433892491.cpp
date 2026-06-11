#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;

	vector<int> cnt(3, 0);
	for (int i = 0; i < s.size(); ++i) {
		int idx = (int)(s[i] - 'a');
		++cnt[idx];
	}
	sort(cnt.rbegin(), cnt.rend());

	bool can = true;
	for (int i = 0; i < 3; ++i) {
		int len = s.size() / 3;
		if (s.size() % 3 > i) { ++len; }
		if (cnt[i] != len) { can = false; }
	}

	if (can) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }

	return 0;
}
