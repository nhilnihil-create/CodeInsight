#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int ans = 0;
	rep(i, n + 1) rep(j, n + 1) {
		if ((n - (r * i + g * j)) % b == 0) {
			int k = (n - (r * i + g * j)) / b;
			if (k >= 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}