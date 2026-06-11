#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m, c; cin >> n >> m >> c;
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int tmp = c;
		for (int j = 0; j < m; j++) {
			tmp += a[i][j] * b[j];
		}
		if (0 < tmp) ans++;
	}
	cout << ans << endl;
	return 0;
}