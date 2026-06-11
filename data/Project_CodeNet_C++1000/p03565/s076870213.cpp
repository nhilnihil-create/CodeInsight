#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s, t; cin >> s >> t;
	
	if (s.size() < t.size()) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}

	vector<bool> hatenaIndex(s.size(), false);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			hatenaIndex[i] = true;
			s[i] = 'a';
		}
	}
	
	vector<string> c;
	for (int i = 0; i < s.size()- t.size() + 1; i++) {		
		bool can = true;
		for (int j = i; j < i + t.size(); j++) {
			if (hatenaIndex[j]) continue;
			if (s[j] != t[j - i]) {
				can = false;
				break;
			}
		}

		if (can) {
			string ans = "";
			for (int j = 0; j < i; j++) ans += s[j];
			ans += t;
			for (int j = i + t.size(); j < s.size(); j++) ans += s[j];
			c.push_back(ans);
		}

	}

	sort(c.begin(), c.end());

	if(c.size()==0) cout << "UNRESTORABLE" << endl;
	else cout << c[0] << endl;
    return 0;
}