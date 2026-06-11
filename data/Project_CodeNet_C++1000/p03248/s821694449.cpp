#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

char s[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s + 1;
	int n = strlen(s + 1);
	bool ok = true;
	if (s[1] == '0') ok = false;
	if (s[n] == '1') ok = false;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[n - i]) ok = false;
	}
	vector<int> p(n + 1, -1);
	vector<int> q(n + 1, -1);
	for (int i = 1; i < (n + 1) / 2; i++) {
		p[i] = i + 1;
		p[n - i + 1] = n - i;
	}
	if (n % 2 == 0) p[n / 2] = n / 2 + 1;
	for (int i = 2; i <= n / 2; i++) {
		if (s[i] == '1') continue;
		q[i] = i + 1;
		if (n % 2 != 0 || i != n / 2) q[n - i + 1] = n - i;
	}
	function<int(int)> find = [&](int x) {
		if (q[x] == -1) return x;
		return q[x] = find(q[x]);
	};
	if (ok) {
		for (int i = 1; i <= n; i++) if (p[i] != -1) cout << i << ' ' << find(p[i]) << "\n";
	}
	else cout << "-1";
	return 0;
}
