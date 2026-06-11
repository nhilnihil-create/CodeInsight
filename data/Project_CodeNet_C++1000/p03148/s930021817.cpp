#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> t(N), d(N);
	for (int i = 0; i < N; ++i) {
		cin >> t[i] >> d[i]; --t[i];
	}
	vector<vector<int> > g(N);
	for (int i = 0; i < N; ++i) {
		g[t[i]].push_back(d[i]);
	}
	vector<long long> cl, cr;
	for (int i = 0; i < N; ++i) {
		if (!g[i].empty()) {
			sort(g[i].begin(), g[i].end(), greater<int>());
			cl.push_back(g[i][0]);
			for (int j = 1; j < g[i].size(); ++j) {
				cr.push_back(g[i][j]);
			}
		}
	}
	sort(cl.begin(), cl.end(), greater<int>());
	sort(cr.begin(), cr.end(), greater<int>());
	vector<long long> sl(cl.size() + 1), sr(cr.size() + 1);
	for (int i = 0; i < cl.size(); ++i) sl[i + 1] = sl[i] + cl[i];
	for (int i = 0; i < cr.size(); ++i) sr[i + 1] = sr[i] + cr[i];
	long long ans = 0;
	for (int i = 0; i <= cl.size() && i <= K; ++i) {
		int t = K - i;
		if (t <= cr.size()) ans = max(ans, 1LL * i * i + sl[i] + sr[t]);
	}
	cout << ans << endl;
	return 0;
}