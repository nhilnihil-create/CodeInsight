#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int a[N], b[N], n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &a[i], &b[i]);
	}
	bool flg = 1;
	for (int i = 1; i <= n; ++i)
		flg &= a[i] == b[i];
	if (flg) {
		puts("0");
		return 0;
	}
	ll mn = 1e18, sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += a[i];
		if (a[i] > b[i]) mn = min(mn, (ll) b[i]);
	}
	if (mn == 1e18) {
		puts("0");
		return 0;
	}
	printf("%lld\n", sum - mn);
	return 0;
}
