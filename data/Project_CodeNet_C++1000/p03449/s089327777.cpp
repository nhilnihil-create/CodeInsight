#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
	int n; cin >> n;
	const int p = 2;
	vector<vector<int>> a(p, vector<int>(n));
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int k = 0; k < n; k++) {
		int tmp = 0;
		for (int j = 0; j <= k; j++) {
			tmp += a[0][j];
		}
		for (int j = k; j < n; j++) {
			tmp += a[1][j];
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
    return 0;
}