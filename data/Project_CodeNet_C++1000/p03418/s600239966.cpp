#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int64_t N, K;
	cin >> N >> K;

	int64_t ans = 0;
	for (int64_t i = K + 1; i <= N; i++) {
		ans += (i - K) * (N / i);
		int64_t n = N % i;
		if (n >= K) ans += n - K + 1;
	}

	if (!K) ans = N * N;

	cout << ans << endl;
}