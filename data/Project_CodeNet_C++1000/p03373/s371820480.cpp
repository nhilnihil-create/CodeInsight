#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	ll a, b, c, x, y, ans = 0;
	cin >> a >> b >> c >> x >> y;
	if (a / 2 + b / 2 < c) ans = a * x + b * y;
	else {
		ans = c * min(x,y) * 2;
		if (x > y && a > c * 2) ans += (x - y) * c * 2;
		if (x > y && a <= c * 2) ans += (x - y) * a;
		if (x < y && b > c * 2) ans += (y - x) * c * 2;
		if (x < y && b <= c * 2) ans += (y - x) * b;
	}
	cout << ans;
	return 0;
}