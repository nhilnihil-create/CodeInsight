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

const int N = 1e5 + 8;
const int INF = 10 * N;

int d[N];
vector<pair<int, int>> g[N];

int dij(int st, int en) {
	fill(d, d + N, INF);
	d[st] = 0;
	deque<int> q;
	q.push_back(st);
	while (!q.empty()) {
		int v = q.front();
		q.pop_front();
		for (auto t : g[v]) {
			if (d[t.first] > d[v] + t.second) {
				d[t.first] = d[v] + t.second;
				if (t.second) q.push_back(t.first);
				else q.push_front(t.first);
			}
		}
	}
	return d[en];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	


	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		g[i].push_back({(i * 10) % n, 0});
		g[i].push_back({(i + 1) % n, 1});
	}
	cout << dij(1, 0) + 1 << endl;
}
