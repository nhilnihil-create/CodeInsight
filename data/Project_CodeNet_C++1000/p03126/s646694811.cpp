#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	vector<int> num(m, 0);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			num[--a]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (num[i] == n) ans++;
	}
	cout << ans << endl;
	return 0;
}