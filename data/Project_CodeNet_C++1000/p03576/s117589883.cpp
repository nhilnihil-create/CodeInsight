#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <utility>

using namespace std;
typedef long long signed int ll;

constexpr ll inf = INT64_MAX / 2;

int main() {
	int n, k;
	vector<pair<int, int>> v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.emplace_back(x, y);
	}
	sort(v.begin(), v.end());
	ll res = inf;
	vector<pair<int, int>> v2;
	for (auto i = v.begin();i + (k-1) < v.end(); i++) {
		for (auto j = i + (k-1); j < v.end(); j++) {
			v2.clear();
			for (auto l = i; l <= j; l++) {
				v2.push_back(*l);
			}
			sort(v2.begin(), v2.end(), [](pair<int, int> a, pair<int, int> b) {
				return a.second < b.second;
				});
			for (auto l = v2.begin(); l != v2.end() && (l+(k-1)) != v2.end(); l++) {
				ll x = j->first - i->first;
				ll y = (l + k - 1)->second - l->second;
				res = min(res, x*y);
			}
		}
	}
	cout << res << endl;
}