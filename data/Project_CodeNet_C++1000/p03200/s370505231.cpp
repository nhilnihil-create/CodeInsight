#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	ll ans = 0;
	while (s.length()>=2) {
		if (s.at(0) == 'W')s = s.substr(1);
		else break;
	}
	if (s.length() == 1) {
		cout << 0 << endl;
		return 0;
	}
	ll w = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == 'W') {
			ans += i;
			w++;
		}
	}
	ans -= w * (w - 1) / 2;
	cout << ans << endl;
}