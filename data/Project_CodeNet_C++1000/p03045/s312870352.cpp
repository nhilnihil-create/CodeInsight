#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 1e5 + 7;

int used[N];
vector<int> g[N];

void dfs(int cur) {
	used[cur] = 1;
	for (auto t : g[cur]) {
		if (!used[t]) {
			dfs(t);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v, kek;
		cin >> u >> v >> kek;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans << endl;
}
