// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	vector<vector<int>> v1(26), v2(26);
	for(int i = 0; i < s.length(); i++) {
		v1[s[i]-'a'].push_back(i);
		v2[t[i]-'a'].push_back(i);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	if(v1 == v2) cout << "Yes";
	else cout << "No";
	return 0;
}
