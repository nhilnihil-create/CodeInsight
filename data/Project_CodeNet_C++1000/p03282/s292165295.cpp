#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define ll long long

int main() {
	string s;
	ll k;
	int ans;

	cin >> s >> k;

	int x = s.size();
	int n = 0;
	rep(i, s.size()) {
		if (s[i] > '1') {
			x = i;
			n = s[i] - '0';
			break;
		}
	}
	if (k <= (ll)x )
		ans = 1;
	else
		ans = n;

	cout << ans << endl;
}
