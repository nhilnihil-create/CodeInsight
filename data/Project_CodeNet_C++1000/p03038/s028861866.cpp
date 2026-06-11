#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<long long>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	vector<vector<int>>cb(m, vector<int>(2));
	for (int i = 0; i < m; i++)cin >> cb.at(i).at(1) >> cb.at(i).at(0);
	sort(a.begin(), a.end());
	sort(cb.begin(), cb.end());
	reverse(cb.begin(), cb.end());
	vector<long long>z;
	int count = 0;
	for (int i = 0; i < m; i++) {
		if (count == n)break;
		for (int j = 0; j < cb.at(i).at(1); j++) {
			z.push_back(cb.at(i).at(0));
			count++;
			if (count == n)break;
		}
	}
	for (int i = 0; i < min(a.size(),z.size()); i++) a.at(i) = max(a.at(i), z.at(i));
	long long ans = 0;
	for (int i = 0; i < n; i++)ans += a.at(i);
	cout << ans << endl;
}