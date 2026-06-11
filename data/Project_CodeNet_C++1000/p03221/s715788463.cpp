#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	vector<int> p(m),y(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i] >> y[i];
		p[i]--;
	}

	vector<vector<int>> vals(n);
	for (int i = 0; i < m; i++) {
		vals[p[i]].emplace_back(y[i]);
	}

	for (int v = 0; v < n; v++) {
		sort(vals[v].begin(), vals[v].end());
	}

	for (int i = 0; i < m; i++) {
		int v = p[i];
		printf("%06d", v + 1);

		int id = lower_bound(vals[v].begin(), vals[v].end(), y[i]) - vals[v].begin();
		printf("%06d", id + 1);
		cout << endl;
	}

	return 0;
}