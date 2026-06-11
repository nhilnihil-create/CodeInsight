#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s, t; cin >> s >> t;	
	vector<string> ans;
	for (int i = 0; i < s.size() - t.size() + 1; i++) {
		bool can = true;
		for (int j = 0; j < t.size(); j++) {
			if (s[i + j] == '?') continue;
			if (!(s[i + j] == t[j])) {
				can = false;
			}
		}
		if (can) {
			string tmp_s = s;
			for (int j = 0; j < t.size(); j++) {
				tmp_s[i + j] = t[j];
			}
			for (int j = 0; j < tmp_s.size(); j++) {
				if (tmp_s[j] == '?') {
					tmp_s[j] = 'a';
				}
			}
			ans.push_back(tmp_s);
		}
	}
	if (ans.size() != 0) {
		sort(ans.begin(), ans.end());
		cout << ans[0] << endl;
	}
	else {
		cout << "UNRESTORABLE" << endl;
	}
	return 0;
}