#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	string s, t;
	cin >> s >> t;
	string ans = s;
	int pos = -1;
	for (int i = 0; i + (int) t.size() <= (int) s.size(); i++) {
		string s_ = s.substr(i, t.size());
		bool flag = true;
		for (int j = 0; j < (int) t.size(); j++) {
			if (s_[j] != '?' && s_[j] != t[j]) {
				flag = false;
				break;
			}
		}
		if (flag) pos = i;
	}
	if (pos != -1) {
		ans.replace(pos, t.size(), t);
		for (int j = 0; j < (int) ans.size(); j++)
			if (ans[j] == '?') ans[j] = 'a';
		cout << ans << endl;
	} else {
		cout << "UNRESTORABLE" << endl;
	}
}