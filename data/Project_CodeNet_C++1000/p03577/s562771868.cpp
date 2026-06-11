#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	string s; cin >> s;
	string ans;
	bool f=false;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (!f && s[i] == 'F') {
			f = true;
			continue;
		}
		if (f) {
			ans.push_back(s[i]);
		}
	}
	reverse(ans.begin(), ans.end());

	cout << ans << endl;
}