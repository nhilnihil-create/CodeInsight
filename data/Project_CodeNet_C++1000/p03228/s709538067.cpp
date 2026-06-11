#include <iostream>

using namespace std;

int main()
{
	int a, b, k;
	cin >> a >> b >> k;

	int t;
	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			if (a % 2 == 1) {
				a--;
			}

			t = a /= 2;
			b += t;
		}
		else {
			if (b % 2 == 1) {
				b--;
			}

			t = b /= 2;
			a += t;
		}
	}
	printf("%d %d\n", a, b);

	return 0;
}