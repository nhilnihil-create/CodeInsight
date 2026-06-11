#include <bits/stdc++.h>
using namespace std;
#define mid ((s + e) / 2)
#define makefast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define comp(x) (lower_bound(vec.begin(), vec.end(), x) - vec.begin())
#define lc (v * 2)
#define rc (v * 2 + 1)
long long M = 1e9 + 7;
//>>>>>>>>>>>>>>>>>>>>>>>

#define int long long

const int N = 1e5 + 7;

int d[N];
int n, sz[N];
map <int, int> who;
vector <int> ad[N];
int sm = 0;

void dfs(int v, int p = 0, int dis = 0) {
	sm += dis;
	for (auto u: ad[v])
		if (u != p)
			dfs(u, v, dis + 1);
}

int32_t main() {
	makefast;
	cin >> n;
	set <int> s;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		who[d[i]] = i;
		s.insert(-d[i]);
		sz[i] = 1;
	}
	while (s.size() > 1) {
		int dis = -*s.begin();
		s.erase(-dis);
		int v = who[dis];
		dis += 2 * sz[v] - n;
		if (!who[dis]) {
			cout << -1;
			return 0;
		}
		int u = who[dis];
	//	cout << v << " <> " << u << " " << dis << endl;
		ad[v].push_back(u);
		ad[u].push_back(v);
		sz[u] += sz[v];
	}
	dfs(1);
	if (d[1] != sm) {
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (auto j: ad[i])
			if (i < j)
				cout << i << ' ' << j << '\n';


}
