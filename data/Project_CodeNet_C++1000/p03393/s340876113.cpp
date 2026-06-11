#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<int, int>;
using V = vector<int>;
using VV = vector<vector<int>>;
int Inf = (1<<30);
ll inf = (1LL<<60);
int main() {
	string s;
	cin >> s;
	if (s == "zyxwvutsrqponmlkjihgfedcba") {
		cout << -1;
		return 0;
	}
	vector<bool> flag(26, false);
	int i;
	for (i = 0; i < s.size(); i++) {
		int tmp = s[i] - 'a';
		flag[tmp] = true;
	}
	if (s.size() != 26) {
		cout << s;
		for (i = 0; i <= 25; i++) {
			if (flag[i]) continue;
			char ans = i + 'a';
			cout << ans;
			return 0;
		}
	}
	string t = s;
	next_permutation(s.begin(), s.end()); // next_permutationは文字列に対しても使える
	 // cout << s;
	for (i = 0; i < s.size(); i++) {
		cout << s[i];
		if (s[i] != t[i]) break;
	}
	return 0;
}