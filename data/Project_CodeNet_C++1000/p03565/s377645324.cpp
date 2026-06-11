#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s, t; cin >> s >> t;
	vector<string> ans;
	int ns = s.size();
	int nt = t.size();
	for (int start = 0; start < ns - nt + 1; start++) {
		bool ok = true;
		for (int i = 0; i < nt; i++) {
			if (s[start + i] == '?') {
				continue;
			}
			if (s[start + i] != t[i]) {
				ok = false;
			}
		}
		if (ok) {
			string z = s;
			for (int j = 0; j < nt; j++) {
				z[start + j] = t[j];
			}
			for (int j = 0; j < ns; j++) {
				if (z[j] == '?') z[j] = 'a';
			}
			ans.push_back(z);
		}
	}
	sort(ans.begin(), ans.end());
	if (ans.size() != 0) cout << ans[0] << endl;
	else cout << "UNRESTORABLE" << endl;
	return 0;
}