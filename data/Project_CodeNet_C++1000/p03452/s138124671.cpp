#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 10, MAXM = 2e5 + 10;
vector<pair<int, int> > vc[MAXN];
vector<pair<int, pair<int, int> > > e;
long long d[MAXN], n, m;
bool se[MAXN];

void dfs(int v, long long dis) {
	d[v] = dis;
	se[v] = 1;
	for (int i = 0; i < vc[v].size(); i++)
		if (!se[vc[v][i].first])
			dfs(vc[v][i].first, dis + vc[v][i].second);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int li, ri, di;
		cin >> li >> ri >> di;
		vc[li].push_back({ri, di});
		vc[ri].push_back({li, -di});
		e.push_back({di, {li, ri}});
	}
	for (int i = 1; i <= n; i++)
		if (!se[i])
			dfs(i, 0);
	for (int i = 0; i < m; i++)
		if (d[e[i].second.second] - d[e[i].second.first] != e[i].first)
			return cout << "No", 0;
	cout << "Yes";
}