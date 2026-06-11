#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	int h_max = 0;
	vector<int> h(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		h_max = max(h_max, h[i]);
	}
	vector<vector<int>> c(h_max, vector<int>(n));
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < h_max; i++) {
			if (i <= h[j] - 1) c[i][j] = 1;
		}
	}
	int ans = 0;
	for (int i = h_max - 1; i >= 0; i--) {
		for (int j = 1; j < n; j++) {
			if (c[i][j - 1] == 1 && c[i][j] == 0) {
				ans++;
			}			
		}
		if (c[i][n - 1] == 1) ans++;
	}
	cout << ans << endl;
	return 0;
}