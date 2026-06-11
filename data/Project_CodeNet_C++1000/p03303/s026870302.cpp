#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int w;
	cin >> w;
	string ans;
	for (int i = 0; i < (int) s.length(); i += w) {
		ans += s[i];
	}
	cout << ans << endl;
	return 0;	
}