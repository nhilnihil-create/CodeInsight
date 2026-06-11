
// C - Ordinary Beauty

// 「和の期待値は期待値の和」 を用いた解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	double n, m, d;
	cin >> n >> m >> d;

	double ans;

	if (d == 0) {
		ans = n / (n * n) * (m - 1);
	} else {
		ans = 2 * (n - d) / (n * n) * (m - 1);
	}

	cout << fixed << setprecision(10);
	cout << ans << endl;

	return 0;
}
