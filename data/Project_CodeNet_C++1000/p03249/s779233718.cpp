// author: Saman Mahdanian
#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int n, size[N], p[N];
map <long long, int> who_is;
vector <int> c[N];
long long d[N];

void contradict_if (bool, string = "no exit msg");
long long dfs (int, int = -1);
int get_par (int);

int32_t main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		who_is[d[i]] = i;
	}

	vector <int> ver(n);
	iota (ver.begin(), ver.end(), 0);
	sort (ver.begin(), ver.end(), [] (int a, int b) {
		return d[a] > d[b];
	});
	int root = ver.back();

	for (int v: ver) {
		if (v == root)
			continue;

		size[v]++;
		contradict_if (size[v] * 2 > n, "size failture");

		p[v] = get_par(v);
		size[p[v]] += size[v];
		c[p[v]].push_back(v);
	}

	contradict_if (dfs(root) != d[root], "Root failed");
	for (int v: ver)
		for (int u: c[v])
			cout << v + 1 << ' ' << u + 1 << endl;
}

void contradict_if (bool condition, string msg) {
	if (!condition)
		return;
	cout << -1;
	// cerr << " " << msg;
	cout << endl;
	exit(0);
}

int get_par (int v) {
	long long pev = d[v] - n + 2 * size[v];
	contradict_if (who_is.find(pev) == who_is.end(), "parent not found");
	return who_is[pev];
}

long long dfs (int v, int pv) {
	long long res = 0;
	for (int u: c[v])
		res += size[u] + dfs(u, v);
	return res;
}

// SamMHD :: 05/12/2018 12:30:04 :: Another Tree...