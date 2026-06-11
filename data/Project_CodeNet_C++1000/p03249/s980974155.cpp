#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
long long rn, n, d[N], s[N];
vector<int> gr[N];
map<long long, int> mp;
void dfs(int v, int h = 0) {
	for (auto u : gr[v])
		dfs(u, h + 1);
	rn += h;
}
int32_t main() {
	ios_base::sync_with_stdio (false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> d[i], mp[d[i]] = i;
	sort(d, d + n, greater<int> ());
	fill(s, s + n + 1, 1);
	for (int i = 0; i < n - 1; i++) {
		int v = mp[d[i]], valpar = d[i] - n + 2 * s[v];
		if (!mp.count(valpar)) {
			cout << -1;
			return 0;
		}
		int par = mp[valpar];
		if (par == v) {
			cout << -1;
			return 0;
		}
		s[par] += s[v], gr[par].push_back(v);
	}
	dfs(mp[d[n - 1]]);
	if (rn != d[n - 1]) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (auto u : gr[i])
			cout << i + 1 << " " << u + 1 << "\n";
	}
	return 0;
}
