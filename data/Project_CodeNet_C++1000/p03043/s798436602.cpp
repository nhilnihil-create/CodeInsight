#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
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

	int n, k; cin >> n >> k;

	double ans = 0.0;
	rep(i, 1, n + 1) {
		int j = i;
		int cnt = 0;
		while (j < k) {
			j <<= 1;
			cnt++;
		}
		ans += pow(0.5, (double)cnt) / (double)n;
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}
