#include<bits/stdc++.h>
#define int long long
#define for1(i, n) for(int i = 1; i <= (n);i++)
using namespace std;
int k, a[123567], l = 2, r = 2;
signed main() {
	cin >> k; for1(i, k)cin >> a[i];
	for (int i = k; i >= 1; i--) {
		if (l % a[i] != 0)l += a[i] - l % a[i];
		r -= r % a[i];
		if (l > r) {
			cout << "-1\n";
			return 0;
		}
		r += a[i] - 1;
	}
	cout << l << ' ' << r << endl;
}