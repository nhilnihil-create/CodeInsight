#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int myfind(int a, vector<int>& v) {
	if (v[a] == a) return a;
	int res = myfind(v[a], v);
	v[a] = res;
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> vp;
	vector<int> vr(n + 1, 0);
	vector<long long int> vw(n + 1, 1);
	for (int i = 1; i <= n; i++) vr[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vp.push_back(make_pair(a, b));
	}
	vector<long long int> res(1, 0);
	for (int i = m - 1; i >= 0; i--) {
		int ra = myfind(vp[i].first, vr);
		int rb = myfind(vp[i].second, vr);

		if (ra == rb) {
			res.push_back(res.back());
			continue;
		}

		long long int now = (vw[ra] - 1) * vw[ra] / 2 + (vw[rb] - 1) * vw[rb] / 2;
		long long int after = (vw[ra] + vw[rb] - 1) * (vw[ra] + vw[rb]) / 2;
		res.push_back(after - now + res.back());
		// myunion(ra, rb, vr);
		vr[ra] = rb;
		vw[rb] += vw[ra];
	}
	reverse(res.begin(), res.end());
	for (int i = 1; i <= m; i++) {
		cout << (long long int)n * (n - 1) / 2 - res[i] << endl;
	}
}
