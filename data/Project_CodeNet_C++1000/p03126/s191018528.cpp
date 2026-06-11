#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> cnt(m);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int city;
			cin >> city;
			cnt[city - 1]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
		if (cnt[i] == n)
			ans++;
	cout << ans << '\n';
	return 0;
}
