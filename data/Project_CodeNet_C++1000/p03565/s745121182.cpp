#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size();
	for (int i = n - m; i >= 0; i--) {
		bool ok = true;
		string res = s;
		for (int j = i; j < i + m; j++) {
			if (res[j] != '?' && res[j] != t[j - i]) {
				ok = false;
				break;
			}
			res[j] = t[j - i];
		}
		if (ok) {
			for (int j = 0; j < n; j++) {
				if (res[j] == '?') res[j] = 'a';
			}
			cout << res;
			return;
		}
	}
	cout << "UNRESTORABLE";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}