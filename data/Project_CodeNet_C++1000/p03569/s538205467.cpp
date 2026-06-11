#include <iostream>
#include <string>
using namespace std;

int a[200010];

int main() {
	string s;
	cin >> s;
	string t = "";
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] != 'x') t += s[i];
	}
	int m = t.size();
	bool ok = true;
	for (int i = 0; i < m; i++) {
		if (t[i] != t[m - i - 1]) ok = false;
	}
	if (!ok) {
		cout << -1 << endl;
	}
	else {
		int ans = 0;
		int p = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'x') {
				a[p]++;
			}
			else {
				p++;
			}
		}
		p++;
		for (int i = 0; i < p / 2; i++) {
			ans += abs(a[i] - a[p - i - 1]);
		}
		cout << ans << endl;
	}
}