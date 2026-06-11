#include <bits/stdc++.h>
using namespace std;

#define int long long
int A, B;

void solve() {
	cin >> A >> B;
	if (A > B) swap(A, B);
	long long prod = 1LL * A * B;
	--prod;
	if (!prod) {
		printf("0\n"); return;
	}

	int s = sqrt(prod);
	if (1LL * (s + 1) * (s + 1) <= prod) ++s;
	if (1LL * s * s > prod) --s;

	long long res = s + s;
	if (s == prod / s) --res;

	// A
	if (A <= s) --res;

	// B
	int a = prod / B;
	if (a && B == prod / a) --res;

	printf("%lld\n", max(0LL, res)); 
}

main() {
	int tt;
	cin >> tt;
	while(tt--) {
		solve();
	}
}