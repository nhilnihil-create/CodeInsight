#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int m; cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) cin >> b[i];
	int j = 0;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		if (b[j] == a[i]) j++;
	}
	if (j == m) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
