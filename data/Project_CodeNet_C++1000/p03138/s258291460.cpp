#include <iostream>
#include <algorithm>
using namespace std;
using i64 = int64_t;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);

	i64 n, x; cin >> n >> x;
	i64* a = new i64[n];
	rep(i, 0, n) cin >> a[i];

	vector<i64> cnt(40);
	rep(i, 0, 40) 
		rep(j, 0, n) cnt[i] += (a[j] >> i & 1);

	// あるところまでは同じ
	i64 ans = 0;
	rep(i, 0, 40) {
		if ((x >> i & 1) == 0) continue;
		i64 tmp = 0;
		rep(j, 0, 40) {
			i64 mul = 1LL << j;

			if (j < i) tmp += max(cnt[j], n - cnt[j]) * mul;
			else if (j == i) tmp += cnt[j] * mul;
			else
			{
				if (x >> j & 1) tmp += (n - cnt[j]) * mul;
				else tmp += cnt[j] * mul;
			}
		}
		ans = max(ans, tmp);
	}
	// 全部同じ
	i64 tmp = 0;
	rep(i, 0, n) tmp += a[i] ^ x;
	cout << max(tmp, ans);
	delete[] a;
	return 0;
}