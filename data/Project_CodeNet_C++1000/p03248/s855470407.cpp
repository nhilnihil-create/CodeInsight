#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int len = s.size();
	reverse(s.begin(), s.end());
	if (s[0] == '1' || s[len - 1] == '0') {
		puts("-1");
		return 0;
	}
	for (int i = 1; i < len; ++i) {
		if (s[i] != s[len - i]) {
			puts("-1");
			return 0;
		}
	}
	int m = 1;
	for (int i = 1; i < len; ++i) {
		printf("%d %d\n", m, i + 1);
		if (s[i] == '1') m = i + 1;
	}
	return 0;
}