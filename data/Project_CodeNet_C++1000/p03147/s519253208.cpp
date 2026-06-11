#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<int> h(n);
	int hMax = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		hMax = max(hMax, h[i]);
	}
	vector<vector<int>> c(hMax, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < hMax; j++) {
			if (h[i] <= j) continue;
			else c[j][i] = 1;
		}
	}
	int ans = 0;
	for (int j = hMax - 1; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				if (c[j][i] == 1) ans++;
			}
			else {
				if (c[j][i + 1] == 0 && c[j][i] == 1) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}