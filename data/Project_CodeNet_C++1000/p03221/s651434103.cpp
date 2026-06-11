#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <utility>
#include <numeric>
#include <queue>
#include <stack>

using ll = long long;
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr ll MOD_LL = ll(1e9 + 7);

int main(void) {
	int n, m;
	cin >> n >> m;
	
	vector<int> p(m), y(m);
	vector< vector<int> > d(n);
	for(int i = 0; i < m; ++i) {
		cin >> p[i] >> y[i];
		p[i]--;
		d[p[i]].push_back(y[i]);
	}
	
	for(int i = 0; i < n; ++i) {
		sort(d[i].begin(), d[i].end());
		d[i].erase(unique(d[i].begin(), d[i].end()), d[i].end());
	}
	
	for(int i = 0; i < m; ++i) {
		int x = p[i];
		int id = lower_bound(d[x].begin(), d[x].end(), y[i]) - d[x].begin();
		printf("%06d%06d\n", x + 1, id + 1);
	}
	
	return 0;
}
