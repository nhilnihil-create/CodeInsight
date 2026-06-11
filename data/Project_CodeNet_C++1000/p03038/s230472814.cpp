#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<pair<int, int>> b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(begin(a), end(a));
	for (int i = 0; i < m; i++) {
		cin >> b[i].second >> b[i].first;
	}
	sort(b.rbegin(), b.rend());
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (j == m) break;
		while (i < n && a[i] <= b[j].first && b[j].second > 0) {
			a[i] = b[j].first;
			b[j].second--;
			i++;
		}
		i--;
		j++;
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += a[i];
	}
	cout << res;
	return 0;
}