#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int64_t sub(int64_t K, int64_t n) {
	int64_t cnt = 0;
	while (n < K) {
		cnt++;
		n *= 2;
	}
	return cnt;
}

int main() {
	int64_t N, K;
	cin >> N >> K;

	int64_t d = N - K;
	if (d < 0) d = 0;
	else d++;

	double ans = (double)d / N;
	int64_t m = min(N, K - 1);
	//cout << ans << endl;

	for (int64_t i = 1; i <= m; i++) {
		int64_t n = sub(K, i);
		//cout << n << endl;
		int64_t x = 1;
		for (int i = 0; i < n; i++) x *= 2;
		x *= N;
		//cout << x << endl;
		ans += (double)1 / x;
	}

	cout << fixed << setprecision(10) << ans << endl;
}