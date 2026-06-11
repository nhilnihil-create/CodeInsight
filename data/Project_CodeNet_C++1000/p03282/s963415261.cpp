#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	ll k;
	cin >> k;
	ll x;
	char y;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) != '1') {
			x = i + 1;
			y = s.at(i);
			break;
		}
	}
	if (k < x)cout << 1 << endl;
	else cout << y << endl;
}