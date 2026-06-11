#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string s;
	cin >> s;

	int n = s.size();
	bool ok = (s[0] == '1') && (s.back() == '0');
	for (int i = 0; i < n - 1; ++i) {
		ok = ok && (s[i] == s[n - 2 - i]);
	}

	if (!ok) {
		cout << "-1\n";
		return 0;
	}

	vector<pair<int, int>> ans;
	int r = n;
	for (int i = n - 1; i > 0; --i) {
		ans.emplace_back(r, i);
		if (s[i - 1] == '1') { r = i; }
	}
	
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}
