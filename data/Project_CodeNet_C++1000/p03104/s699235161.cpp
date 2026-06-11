#include <iostream>

using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;

	if (a % 2 == 0) {
		if (b % 2 == 0) {
			cout << (b ^ ((b - a) / 2 % 2)) << endl;
		} else {
			cout << (b - a + 1) / 2 % 2 << endl;
		}
	} else {
		if (b % 2 == 0) {
			cout << (((b - a - 1) / 2 % 2) ^ a ^ b) << endl;
		} else {
			cout << (a ^ ((b - a) / 2 % 2)) << endl;
		}
	}

	return 0;
}