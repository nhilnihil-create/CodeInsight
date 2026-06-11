#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int st[26], ts[26];
	fill(begin(st), end(st), -1);
	fill(begin(ts), end(ts), -1);
	bool ans = true;
	for (int i = 0; i < n; i++) {
		int si = s[i] - 'a', ti = t[i] - 'a';
		if (st[si] != -1 && st[si] != ti) {
			ans = false;
			break;
		}
		if (ts[ti] != -1 && ts[ti] != si) {
			ans = false;
			break;
		}
		st[si] = ti;
		ts[ti] = si;
	}
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}