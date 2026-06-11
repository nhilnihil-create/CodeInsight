#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;	
	vector<pair<int, int>> pa;
	vector<vector<int>> c(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--;
		pa.push_back({ a,b });
		c[a].push_back(b);
	}
	for (int i = 0; i < c.size(); i++) {
		sort(c[i].begin(), c[i].end());		
	}
	for (int i = 0; i < m; i++) {
		int x = pa[i].second;
		// int index = find(c[pa[i].first].begin(), c[pa[i].first].end(), x) - c[pa[i].first].begin();
		int index = upper_bound(c[pa[i].first].begin(), c[pa[i].first].end(), x) - c[pa[i].first].begin() - 1;
		cout << setw(6) << setfill('0') << pa[i].first + 1 << setw(6) << setfill('0') << index + 1 << endl;
	}	
	return 0;
}