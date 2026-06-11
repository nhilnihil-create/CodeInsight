#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<pair<int, int>> x(m);
	for (int i = 0; i < m; i++) {
		cin >> x[i].first >> x[i].second;
	}
	sort(x.begin(), x.end(),
		 [](const pair<int, int> &p, const pair<int, int> &q) {
			 return p.second > q.second;
		 });
	vector<int> d;
	bool fill = false;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < x[i].first; j++) {
			d.push_back(x[i].second);
			if (d.size() == n) {
				fill = true;
				break;
			}
		}
		if (fill) {
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (d.size() > i && d[i] >= a[i]) {
			a[i] = d[i];
		}
	}
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}