#include <bits/stdc++.h>
using namespace std;

const int nm = 1e5;
int n, m, p[nm], r[nm], a[nm], ans = 0;
vector<int> g[nm];

int root(int v) {
	if (r[v] == v)
		return v;
	return root(r[v]);
}
void unite(int x, int y) {
	int rx = root(x), ry = root(y);
	if (rx == ry)
		return;
	if (a[ry] > a[rx])
		swap(rx, ry);
	r[ry] = rx;
	a[rx] += a[ry] + 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		r[i] = i;
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0, x, y; i < m; i++) {
		cin >> x >> y;
		unite(x - 1, y - 1);
	}
	for (int i = 0; i < n; i++)
		if (root(p[i]) == root(i))
			ans++;
	cout << ans << endl;
}
