#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int k; cin >> k;
	map<string, int> mp;
	for (int num = 1; num <= k; num++) {
		for (int i = 0; i < s.size() - num + 1; i++) {
			mp[s.substr(i, num)] = 1;
		}
	}
	int i = 1;
	string ans;
	for (auto u : mp) {
		if (i == k) {
			ans = u.first;
			break;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}