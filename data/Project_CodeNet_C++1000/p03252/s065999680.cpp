#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(string inPut, string target) {
	bool res = true;
	map<char, char> mp;
	for (int i = 0; i < inPut.size(); i++) {
		if (mp.count(inPut[i])) {
			if (mp[inPut[i]] != target[i]) {
				res = false;
			}
		}
		mp[inPut[i]] = target[i];
	}
	return res;
}

int main() {
	
	string s, t; cin >> s >> t;
	bool can1 = check(s, t);
	bool can2 = check(t, s);
	if (can1 && can2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}