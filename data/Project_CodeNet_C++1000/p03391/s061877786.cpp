#include <iostream>
#include <algorithm>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
constexpr i64 INF = 1LL << 60;

int main() {
	int n; cin >> n;
	i64* a = new i64[n];
	i64* b = new i64[n];
	rep(i, 0, n) cin >> a[i] >> b[i];

	int e = 0;
	i64 ans = 0;
	i64 bmin = INF;
	rep(i, 0, n) {
		if (a[i] > b[i]) {
			bmin = min(bmin, b[i]);
		}
		ans += a[i];
		e += a[i] == b[i];
	}
	if (e == n) {
		cout << 0 << endl;
		return 0;
	}
	cout << ans - bmin << endl;

	delete[] a;
	delete[] b;
	return 0;
}