#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	if(n == 3) {
		cout << "2 5 63" << '\n';
		return 0;
	}
	const int a[] = {2, 3, 4, 6};
	int ans[n];
	int off = 0, sum = 0;
	int k = 0;
	for(k = 0; k < n; ++k) {
		ans[k] = off + a[k % 4];
		sum += ans[k];
		if(k % 4 == 3) {
			off += 6;
		}
	}
	k %= 4;
	if(sum % 6 == 2) {
		if(k > 2) off += 6;
		ans[3] = off + 4;
	}
	if(sum % 6 == 3) {
		if(k > 1) off += 6;
		ans[3] = off + 3;
	}
	if(sum % 6 == 5) {
		if(k > 1) off += 6;
		ans[4] = off + 3;
	}
	sort(ans, ans + n);
	// int tmp = 0;
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << (i == n - 1 ? "\n" : " ");
		// tmp += ans[i];
	}
	// for(int i = 0; i < n; ++i) {
	// 	assert(__gcd(ans[i], tmp) > 1);
	// }
	return 0;
}

