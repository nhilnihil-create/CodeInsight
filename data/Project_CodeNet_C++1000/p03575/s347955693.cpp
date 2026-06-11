#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;
int main()
{
	// ABC075-C, 1068, 
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	vector<P> p(m);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		p[i] = make_pair(a, b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		vector<vector<int>> gg = g;
		gg[p[i].first].erase(find(gg[p[i].first].begin(), gg[p[i].first].end(), p[i].second));
		gg[p[i].second].erase(find(gg[p[i].second].begin(), gg[p[i].second].end(), p[i].first));

		vector<int> dist(n, -1);
		queue<int> que;

		dist[0] = 0;
		que.push(0);

		while (!que.empty()) {
			int v = que.front();
			que.pop();

			for (int nv : gg[v]) {
				if (dist[nv] != -1) continue;

				dist[nv] = dist[v] + 1;
				que.push(nv);
			}
		}

		bool ok = true;
		rep(j, n) {
			if (dist[j] == -1) ok = false;
		}
		if (!ok) ans++;
	}
	cout << ans << endl;
  return 0;
}