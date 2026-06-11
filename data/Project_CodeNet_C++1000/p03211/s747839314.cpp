#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int n  = (int)s.size();
	int ans = 1e9;
	for (int i = 1; i  + 1 < n; ++i) {
		int p = (s[i] - '0') * 10 + (s[i + 1] - '0') + (s[i - 1] - '0')*100;
		ans = min(ans,abs(p - 753));
	}
	cout << ans;
}
