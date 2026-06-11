#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long> D(N);
	vector<int> p(N);
	for (int i = 0; i < N; ++i) {
		cin >> D[i];
		p[i] = i;
	}
	sort(p.begin(), p.end(), [&](int i, int j) { return D[i] > D[j]; });
	vector<long long> ds = D;
	for (int i = 0; i < N; ++i) ds[i] *= -1;
	sort(ds.begin(), ds.end());
	vector<int> cnt(N, 1);
	bool ok = true;
	vector<pair<int, int> > edges;
	for (int i = 0; i < N - 1; ++i) {
		long long tar = -ds[i] - (N - 2 * cnt[p[i]]);
		int u = lower_bound(ds.begin(), ds.end(), -tar) - ds.begin();
		if (u == N || -ds[u] != tar) {
			ok = false;
			break;
		}
		cnt[p[u]] += cnt[p[i]];
		edges.push_back(make_pair(p[u], p[i]));
	}
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		if (i != p[N - 1]) {
			sum += cnt[i];
		}
	}
	if (sum != -ds[N - 1]) ok = false;
	if (!ok) {
		cout << -1 << endl;
	}
	else {
		for (pair<int, int> i : edges) {
			cout << i.first + 1 << ' ' << i.second + 1 << endl;
		}
	}
	return 0;
}