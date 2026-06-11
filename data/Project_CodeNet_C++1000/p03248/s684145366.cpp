#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	int n = s.size();
	if (s[0] == '0' || s[n - 2] == '0' || s[n - 1] == '1') {
		cout << -1 << '\n';
		return 0;
	}
	vector<int> v;
	for (int i = 1; i <= (n >> 1); ++i) {
		if (s[i - 1] != s[n - i - 1]) {
			cout << -1 << '\n';
			return 0;
		}
		if (s[i - 1] == '1') v.push_back(i);
	}
	
	if (v.size() == 1) {
		for (int i = 1; i < n; ++i) {
			cout << 1 << ' ' << i + 1 << '\n';
		}
		return 0;
	}

	cout << 1 << ' ' << 2 << '\n';
	int c = 2;
	for (int i = 1; i < v.size(); ++i) {
		for (int j = 1; j < v[i] - v[i - 1]; ++j) {
			cout << c << ' ' << c + j << '\n';
		}
		cout << c << ' ' << v[i] + 1 << '\n';
		c = v[i] + 1;
	}
	for (int i = 1; i < n - v.back(); ++i) {
		cout << c << ' ' << c + i << '\n';
	}
	return 0;
}