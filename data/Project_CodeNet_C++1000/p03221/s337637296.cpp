#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<vector<pair<long long, int>>> mm(n);
	for (int i = 0; i < m; i++) {
		int p;
		long long y;
		cin >> p >> y;
		mm[p-1].push_back(make_pair(y, i));
	}
	for (int i = 0; i < n; i++) {
		sort(mm[i].begin(), mm[i].end());
	}
	vector<pair<int, long long>> ans;
	for (long long i = 0; i < n; i++) {
		for (auto it = mm[i].begin(); it != mm[i].end(); it++) {
			ans.push_back(make_pair(it->second, (i+1)*1000000 + distance(mm[i].begin(), it)+1));
		}
	}
	sort(ans.begin(), ans.end());
	for (auto e : ans) {
		printf("%012lld\n", e.second);
	}

	return 0;
}