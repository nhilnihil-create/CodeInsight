#include <bits/stdc++.h>
using namespace std;

int best[1 << 26];

int main() {
	string s;
	cin >> s;
	int n = s.size(), a[n + 1]{};
	for (int i = 0; i < n; i++) {
		a[i + 1] = a[i] ^ (1 << (s[i] - 'a'));
	}
	int f[n + 1]{}, inf = 1e9;
	fill(best, best + (1 << 26), inf);
	best[a[0]] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = inf;
		for (int bit = -1; bit < 26; bit++) {
			int new_a = a[i];
			if (0 <= bit) {
				new_a ^= (1 << bit);
			}
			f[i] = min(f[i], best[new_a] + 1);
		}
		best[a[i]] = min(best[a[i]], f[i]);
	}
	cout << f[n] << endl;
	return 0;
}