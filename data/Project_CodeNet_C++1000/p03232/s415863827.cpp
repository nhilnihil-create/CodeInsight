#include <bits/stdc++.h>
using namespace std;

const int DIM = 200005;
const int MOD = 1000000007;

int psm[DIM];

int logPower (int x, int n)
{
	int y = 1;
	for (; n; n >>= 1) {
		if (n & 1) 
			y = 1LL * y * x % MOD;
		x = 1LL * x * x % MOD;
	}
	return y;
}

int main (void)
{
#ifdef HOME
	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);
#endif
	int N; cin >> N;
	for (int i = 1; i <= N; ++i) 
		psm[i] = (psm[i - 1] + logPower(i, MOD - 2)) % MOD;
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int x; cin >> x;
		ans = (1LL * (psm[i] + psm[N - i + 1] - 1) * x + ans) % MOD;
	}
	for (int i = 1; i <= N; ++i) 
		ans = 1LL * ans * i % MOD; 
	cout << ans;
	return 0;
}
