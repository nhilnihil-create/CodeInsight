#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int>ac;
	for (int i = 1; i < s.length(); i++) {
		if (s.at(i - 1) == 'A' && s.at(i) == 'C') {
			ac.push_back(i - 1);
		}
	}
	for (int i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		ll ans = (lower_bound(ac.begin(), ac.end(), r) - ac.begin()) - (lower_bound(ac.begin(), ac.end(), l) - ac.begin());
		cout << ans << endl;
	}
}