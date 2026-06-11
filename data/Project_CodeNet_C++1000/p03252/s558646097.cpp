#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	vector<int> a(26, -1), b(26, -1);
	rep(i, n) {
		a[s[i] - 'a'] = t[i] - 'a';
		b[t[i] - 'a'] = s[i] - 'a';
	}
	bool ch = 0;
	rep(i, n) {
		if (t[i] != a[s[i] - 'a'] + 'a') ch = 1;
		if (s[i] != b[t[i] - 'a'] + 'a') ch = 1;
	}
	rep(i, 26) {
		if (a[i] == -1) continue;
		if (i != b[a[i]]) ch = 1;
	}
	if (ch)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}