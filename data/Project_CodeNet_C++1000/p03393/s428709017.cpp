#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	vector<int>a(s.length());
	vector<int>c(26,0);
	for (int i = 0; i < s.length(); i++) {
		a.at(i) = s.at(i) - 'a';
		c.at(a.at(i))++;
	}
	if (s.length() <= 25) {
		ll ans;
		for (int i = 0; i < 26; i++) {
			if (c.at(i) == 0) {
				ans = i;
				break;
			}
		}
		char c = 'a' + ans;
		cout << s << c << endl;
	}
	else {
		set<int>b;
		b.insert(a.at(s.length() - 1));
		a.at(s.length() - 1) = -1;
		for (int i = 1; i < 26; i++) {
			int d = a.at(s.length() - 1 - i);
			for (auto e : b) {
				if (e > d) {
					char f = 'a' + e;
					cout << s.substr(0,26-i-1) << f << endl;
					return 0;
				}
			}
			b.insert(d);
			a.at(s.length() - 1 - i) = -1;
		}
		cout << -1 << endl;
	}
}
