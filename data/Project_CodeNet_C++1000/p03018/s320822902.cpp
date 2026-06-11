#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s; cin >> s;
	ll ans = 0;
	ll acount = 0;
	ll cskip = -1;
	for (int i = 0; i < s.length(); i++) {
		if (i == cskip) {
			cskip = -1;
			continue;
		}
		if (s.at(i) == 'A')acount++;
		else if (s.at(i) == 'B') {
			if (i + 1 >= s.length())break;
			if (s.at(i + 1) == 'C') {
				ans += acount;
				cskip = i + 1;
			}
			else {
				acount = 0;
				cskip = -1;
			}
		}
		else {
			acount = 0;
			cskip = -1;
		}
	}
	cout << ans << endl;
}