#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	long x, y;
	cin >> x >> y;
	int ans = 0;
	while (y >= x) {
		y >>= 1;
		ans++;
	}
	cout << ans << endl;
}