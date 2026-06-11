#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(size_t i = (j); i < (n); ++i)
#define rrep(i, j, n) for(size_t i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int n, a, b, c;
vector<int> l;
int ans = 1 << 30;


void dfs(int i, int cost, int alen, int blen, int clen) {
	if (i == n) {
		if (alen == 0 || blen == 0 || clen == 0) return;
		ans = min(ans, cost + abs(a - alen) + abs(b - blen) + abs(c - clen));
		return;
	}

	if (alen > 0) dfs(i + 1, cost + 10, alen + l[i], blen, clen);
	else dfs(i + 1, cost, alen + l[i], blen, clen);

	if (blen > 0) dfs(i + 1, cost + 10, alen, blen + l[i], clen);
	else dfs(i + 1, cost, alen, blen + l[i], clen);

	if (clen > 0) dfs(i + 1, cost + 10, alen, blen, clen + l[i]);
	else dfs(i + 1, cost, alen, blen, clen + l[i]);

	dfs(i + 1, cost, alen, blen, clen);
	return;
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	cin >> n >> a >> b >> c;
	l.resize(n);
	rep(i, 0, n) cin >> l[i];

	dfs(0, 0, 0, 0, 0);
	cout << ans << endl;

	return 0;

}
