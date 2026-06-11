#include<bits/stdc++.h>
#define int long long
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define puts(x) cout << x << endl
using namespace std;
int input() {
	int r;
	scanf("%lld", &r);
	return r;
}
int n, k, a[123456], sum, p = 1099511627776, ans;
signed main() {
	cin >> n >> k; for1(i, n)a[i] = input();
	while (p) {
		if (sum + p <= k) {
			int cnt = 0;
			for1(i, n)cnt += a[i] / p % 2;
			if (cnt < n - cnt)sum += p;
		}
		p /= 2;
	}
	for1(i, n)ans += a[i] ^ sum;
	puts(ans);
}