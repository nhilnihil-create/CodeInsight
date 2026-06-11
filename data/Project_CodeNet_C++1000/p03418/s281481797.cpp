#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k;

int main() {
	
	cin >> n >> k;
	intt ans = 0;
	for (int b = k + 1; b <= n; b ++) {
		int x = n / b, m = n % b;
		if (x > 0) ans += 1LL * x * (b - k);
		if (m >= k) ans += m - k + 1;
	}
	if (!k) ans -= n;
	cout << ans << '\n';
}