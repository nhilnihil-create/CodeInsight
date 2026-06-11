#include <bits/stdc++.h>

#define sz(x) ((int)x.size())

using namespace std;











int main() {
	string s;
	int ans;
	cin >> s;
	ans = sz(s);
	for (int i = 0; i < sz(s) - 1; i++)
		if (s[i] != s[i + 1])
			ans = min(ans, max(i + 1, sz(s) - i - 1));
	cout << ans;
	return 0;
}