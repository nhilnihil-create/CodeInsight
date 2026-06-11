#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main() {
	// input
	string s; cin >> s;
	int n = s.length();
	// 自明に不可能なものに-1を出力
	if (s[0] != '1' || s[n - 1] != '0' || s[n - 2] != '1') {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 2; i < n; ++i) {
		if (s[i - 1] != s[n - i - 1]) {
			cout << "-1" << endl;
			return 0;
		}
	}
	// 構築
	cout << "1 2" << endl;
	int on_path = 2;
	for (int i = 1; i < n - 1; ++i) {
		cout << on_path << " " << (i + 2) << endl;
		if (s[i] == '1') on_path = (i + 2);
	}
	return 0;
}