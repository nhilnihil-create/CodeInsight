#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s, t; cin >> s >> t;
	
	const int p = 26;
	vector<int> s_num(p), t_num(p);

	for (int i = 0; i < s.size(); i++) {
		s_num[s[i] - 'a']++;
		t_num[t[i] - 'a']++;
	}

	sort(s_num.begin(), s_num.end());
	sort(t_num.begin(), t_num.end());
	
	bool can = true;
	for (int i = 0; i < p; i++) {
		if (s_num[i] != t_num[i]) {
			can = false;
		}
	}
	
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}