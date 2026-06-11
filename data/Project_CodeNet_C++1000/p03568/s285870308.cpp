#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans = 1, cur = 1;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ans *= 3;
		if (x & 1) cur *= 1;
		else cur *= 2;
	}
	cout << ans - cur << endl;
	return 0;
}

