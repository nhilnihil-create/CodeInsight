#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> h(n);
	int h_max = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		h_max = max(h_max, h[i]);
	}

	if (n == 1) {
		cout << h[0] << endl;
		return 0;
	}

	vector<vector<int>> c(h_max, vector<int>(n, 0));

	for (int i = h_max - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (i <= h[j] - 1) c[i][j] = 1;
		}
	}

	int ans = 0;
	for (int i = h_max - 1; i >= 0; i--) {		
		for (int j = 0; j < n - 1; j++) {
			if (c[i][j] == 1 && c[i][j + 1] != 1) {
				ans++;
			}
			else if (j == n - 2 && c[i][j + 1] == 1) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}