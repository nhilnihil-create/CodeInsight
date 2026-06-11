// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	vector<int> v1(26, 0), v2(26, 0);
	for(int i = 0; i < s.length(); i++) {
		v1[s[i] - 'a']++;
		v2[t[i] - 'a']++;
	}
	for(int i = 0; i < s.length(); i++) {
		if(v1[s[i] - 'a'] != v2[t[i] - 'a']) {
			cout << "No";
			exit(0);
		}
	}
	cout << "Yes";
	return 0;
}
