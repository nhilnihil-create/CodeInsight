#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	ll ans = 0;
	for (int i = 0; i <= n / r; i++) {
		int t = n - (i * r);
		for (int j = 0; j <= t / g; j++) {
			int u = t - (j * g);
			if (u % b == 0)ans++;
		}
	}
	cout << ans << endl;
}