#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int a, b, c;
	int ans = 0;
	cin >> a >> b >> c;
	if (a > b) {
		ans += b;
		if (a > c) ans += a * 10 + c;
		else ans += c * 10 + a;
	}
	else {
		ans += a;
		if (b > c) ans += b * 10 + c;
		else ans += c * 10 + b;
	}
	cout << ans << endl;
	return 0;
}