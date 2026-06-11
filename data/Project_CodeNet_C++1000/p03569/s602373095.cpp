#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	vector<char>a;
	vector<int>xs = { 0 };
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) != 'x') {
			a.push_back(s.at(i));
			xs.push_back(0);
		}
		else xs.at(xs.size() - 1)++;
	}
	for (int i = 0; i < a.size() / 2; i++) {
		if (a.at(i) != a.at(a.size() - 1 - i)) {
			cout << -1 << endl;
			return 0;
		}
	}
	ll ans = 0;
	for (int i = 0; i < xs.size() / 2; i++) {
		ans += abs(xs.at(i) - xs.at(xs.size() - 1 - i));
	}
	cout << ans << endl;
}