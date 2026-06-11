

#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int max, min, mid;
	cin >> a >> b >> c;

	int x = 10 * a + b + c;
	int y = 10 * b + a + c;
	int z = 10 * c + a + b;
	int ans;
	if (x >= y) {
		if (x >= z) {
			ans = x;
		}
		else {
			ans = z;
		}
	}
	else {
		if (y >= z) {
			ans = y;
		}
		else {
			ans = z;
		}
	}

	cout << ans << endl;
}

