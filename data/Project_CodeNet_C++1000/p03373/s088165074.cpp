#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a, b, c, x, y, mini; cin >> a >> b >> c >> x >> y;
	c *= 2; mini = min(x, y);
	int ans = mini * min(a + b, c);
	x -= mini, y -= mini;
	if (x) {
		ans += min(a, c) * x;
	}
	if (y) {
		ans += min(b, c) * y;
	}
	cout << ans << endl;

	return 0;
}