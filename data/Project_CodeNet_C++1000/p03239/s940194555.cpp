#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	int ans = 1e9;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		if (y <= t) {
			ans = min(ans,x);
		}
	}
	if (ans != 1e9) 
		cout << ans;
	else 
		cout << "TLE";
}
