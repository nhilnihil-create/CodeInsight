#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int now = 0;
	ll ans = 0;
	rep(i, s.size()) {
		if (s[i] == 'W') {
			if (now != i) ans += i - now;
			now++;
		}
	}
	cout << ans << endl;
	return 0;
}