#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;



int main() {
	int z;
	cin >> z;

	int a;
	int b;
	int c;
	int d;

	d = z % 10;
	z -= d;
	c = (z % 100) / 10;
	z -= c * 10;
	b = (z % 1000) / 100;
	a = (z - b * 100) / 1000;

	int eq;
	char o1, o2, o3;
	for (int bit = 0; bit < (1 << 3); bit++) {
		if (bit & (1 << 0)) {
			eq = a + b;
			o1 = '+';
		}
		else {
			eq = a - b;
			o1 = '-';
		}
		if (bit & (1 << 1)) {
			eq = eq + c;
			o2 = '+';
		}
		else {
			eq = eq - c;
			o2 = '-';
		}
		if (bit & (1 << 2)) {
			eq = eq + d;
			o3 = '+';
		}
		else {
			eq = eq - d;
			o3 = '-';
		}
		if (eq == 7) {
			cout << a << o1 << b << o2 << c << o3 << d << "=7" << endl;
			return 0;
		}
	}

	return 0;
}