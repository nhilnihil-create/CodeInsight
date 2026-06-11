#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int train;
	int bus;
	if (a < b) {
		train = a;
	} else {
		train = b;
	}
	if (c < d) {
		bus = c;
	} else {
		bus = d;
	}
	int ans = train + bus;
	cout << ans << endl;
	return 0;
}