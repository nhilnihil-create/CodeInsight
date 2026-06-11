#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i < n; i++)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s, t;
	cin >> s >> t;
	vector<string> valid;
	int n = s.size(), m = t.size();
	rep(i, n - m + 1) {
		string ret = s;
		bool ok = true;
		rep(j, m) {
			if(ret[i+j] == '?') {
				ret[i+j] = t[j];
			}
			else if(ret[i+j] != t[j]) {
				ok = false;
			}
		}
		rep(j, n)if(ret[j] == '?')ret[j] = 'a';
		if(ok)valid.push_back(ret);
	}
	if(valid.size() == 0) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	sort(valid.begin(), valid.end());
	cout << valid[0] << endl;
}
