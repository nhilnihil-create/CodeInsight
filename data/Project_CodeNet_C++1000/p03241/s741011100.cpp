#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)

constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m; cin >> n >> m;

	int ans = 1;
	for (int i = 1; i * i <= m; ++i) {
		if (m % i == 0) {
			if (m / i >= n) ans = max(ans, i);
			if (i >= n) ans = max(ans, m / i);
		}
	}
	cout << ans << endl;
	return 0;
}
