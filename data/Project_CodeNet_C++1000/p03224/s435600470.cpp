#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int k = 1;
	while (k * (k + 1) / 2 < n) k++;
	if (k * (k + 1) / 2 != n) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	k++;
	cout << k << endl;
	vector<vector<int>> ans(k);
	int c = 1;
	for (int i = 1; i < k; i++) {
		int t = 0;
		for (int j = i; j >= 1; j--) {
			ans[t].push_back(c);
			ans[t + j].push_back(c);
			t++;
			c++;
		}
	}
	for (int i = 0; i < k; i++) {
		cout << ans[i].size() << " ";
		for (int j = 0; j < (int) ans[i].size(); j++) {
			if (j > 0) cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;	
}
