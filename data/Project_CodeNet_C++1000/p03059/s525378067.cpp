#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, t;
	cin >> a >> b >> t;
	int ans = 0, newA = a;
	for (int i = 0; i < t + 1; i++) {
		if (i == newA) {
			ans += b;
			newA += a;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
