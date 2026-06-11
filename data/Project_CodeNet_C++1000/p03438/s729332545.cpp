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
	i64 a[10000], b[10000];
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];

	i64 sa = 0, sb = 0;
	i64 ca = 0, cb = 0;
	rep(i, 0, n) {
		sa += a[i];
		sb += b[i];
		if (a[i] > b[i]) cb += a[i] - b[i];
		else ca += (b[i] - a[i] + 1) / 2;
	}
	if (sb - sa >= max(ca, cb)) cout << "Yes";
	else cout << "No";

	return 0;
}