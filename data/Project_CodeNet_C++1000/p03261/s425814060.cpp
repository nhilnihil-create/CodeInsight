#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	map<string, int> mp;
	bool can = true;
	for (int i = 0; i < n; i++) {
		char last;
		string w; cin >> w;
		mp[w]++;
		if (i != 0 && last != w[0]) {
			can = false;
		}
		last = w.back();
	}
	for (auto u : mp) {
		if (2 <= u.second) can = false;
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}