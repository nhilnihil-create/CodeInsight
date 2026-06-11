#include <bits/stdc++.h>
using namespace std;

int n, ans;
string s;

signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> s;
	ans = n = s.size();
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] != s[i + 1])
			ans = min(ans, max(n - i - 1, i + 1));
	}
	printf("%d\n", ans);
}
