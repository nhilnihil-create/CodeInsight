#include <bits/stdc++.h>
using namespace std;
string s;
unordered_map<int, int> M;
int main () {
	ios::sync_with_stdio(false);
	cin >> s;
	int stat = 0;
	int l = s.length();
	M[0] = 0;
	for (int i = 0; i < l; i++) {
		stat ^= (1 << (s[i] - 'a'));
		int mi = 123456789;
		for (int j = 0; j < 26; j++) {
			auto k = M.find(stat ^ (1 << j));
			if (k != M.end()) mi = min(mi, k -> second);
		}
		auto k = M.find(stat);
		if (k != M.end()) k -> second = min(k -> second, mi + 1);
		else M[stat] = mi + 1;
	}
	if (!stat) cout << 1 << endl;
	else cout << M[stat] << endl;
	return 0;
}