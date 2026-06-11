#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef HOME
	freopen("arc95d.in", "r", stdin);
	freopen("arc95d.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	vector<int> v;
	int n, best;

	cin >> n;
	v.resize(n);
	for (auto &i: v)
		cin >> i;

	sort(begin(v), end(v));
	best = v[0];
	for (int i = 1; i < n; ++i)
		if (min(best, v[n - 1] - best) < min(v[i], v[n - 1] - v[i]))
			best = v[i];

	cout << v[n - 1] << ' ' << best << '\n';

	return 0; }

