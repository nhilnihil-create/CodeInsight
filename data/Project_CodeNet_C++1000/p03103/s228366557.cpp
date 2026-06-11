#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)


constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k; cin >> n >> k;
	vector<pair<int, int>> a;
	rep(i, 0, n) {
		int b, c; cin >> b >> c;
		a.emplace_back(b, c);
	}
	sort(a.begin(), a.end());

	ll ans = 0;
	int i = 0;
	while (k) {
		ll d = min(k, a[i].second);
		ans += d * a[i].first;
		k -= d;
		i++;
	}
	cout << ans;
	return 0;
}