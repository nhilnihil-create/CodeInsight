#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		mp[s]++;
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		string t; cin >> t;
		mp[t]--;
	}
	int ans = 0;
	for (auto u : mp) {
		ans = max(ans, u.second);
	}
	cout << max(0, ans) << endl;
    return 0;
}