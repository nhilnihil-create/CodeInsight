#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), greater<char>());
	int a = (int)s.size();
	int b = (int)t.size();
	bool ok = false;
	rep(i, b) {
		if (s[i] < t[i]) {
			ok = true;
			break;
		}
		if (s[i] > t[i]) {
			ok = false;
			break;
		}
		if (s[i] == t[i] && i == a) {
			ok = false;
			break;
		}
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}