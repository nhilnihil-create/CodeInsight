#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
	string s;
	cin >> s;
	int bn = 0;
	ll ans = 0;
	rep(i, s.size()) {
		if (s[i] == 'B') bn++;
		else ans += bn;
	}
	cout << ans << endl;
	return 0;
}