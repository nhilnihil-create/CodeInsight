#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;


int main(void) {
	int n, i, j, a, b, c[10003], ans[10003], p, t, m;
	vector<int> g[10003];
	queue<int> q;
	bool u[10003] = { false };

	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}

	for (i = 0; i < n; i++) {
		cin >> c[i];
	}

	sort(c, c + n, greater<int>());

	q.push(0);
	t = 0;
	m = 0;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		u[p] = true;
		ans[p] = c[t++];
		for (i = 0; i < g[p].size(); i++) {
			if (!u[g[p][i]]) {
				q.push(g[p][i]);
			}
		}
		m += c[t];
	}

	cout << m << endl;
	for (i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;

	return 0;
}