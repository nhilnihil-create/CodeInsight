#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n, a, b, cnt = 1, ans = 0;
	cin >> n >> a;
	for (int i = 0; i < n - 1; ++i){
		cin >> b;
		if (b == a) 
			++cnt;
		else {
			ans += cnt / 2;
			cnt = 1;
		}
		a = b;
	}
	ans += cnt / 2;
	cout << ans << '\n';
}
