#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100005;

int main() {
	int n, m;
	cin >> n >> m;
	struct S
	{
		int p, y, idx;
	};
	auto comp = [&](S a, S b) -> bool {
		return a.y < b.y;
	};
	vector<S> v;
	for (int i = 0; i < m; i++) {
		int p, y;
		cin >> p >> y;
		v.push_back({p, y, i});
	}
	sort(v.begin(), v.end(), comp);
	vector<int> id(MAX, 0);
	vector<pair<int, int>> ans(m);
	for (S e : v) {
		id[e.p]++;
		int x = id[e.p];
		ans[e.idx].second = x;
		ans[e.idx].first = e.p;
	}
	for (auto e : ans) {
		printf("%06d%06d\n", e.first, e.second);
	}
	return 0;
}