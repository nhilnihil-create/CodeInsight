#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr i64 MOD = 1000000007;
constexpr i64 INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<pair<int, int>> p;
	rep(i, 0, n) {
		int a;
		cin >> a;
		p.emplace_back(a, i);
	}
	sort(p.begin(), p.end());
	vector<int> ans(n);

	rep(i, 0, n) {
		int j = p[i].second;
		if (i < n / 2) ans[j] = p[n / 2].first;
		else ans[j] = p[n / 2 - 1].first;
	}
	rep(i, 0, n) cout << ans[i] << '\n';
	return 0;
}