#include <iostream>
#include <string>

using namespace std;

int main() {
	string op;
	string ABCD;
	int seven;
	int a, b, c, d;

	cin >> ABCD;

	a = ABCD[0] - '0';
	b = ABCD[1] - '0';
	c = ABCD[2] - '0';
	d = ABCD[3] - '0';

	for (int bit = 0; bit < (1 << 3); bit++) {
		op = "---";
		seven = 0;
		for (int i = 0; i < 3; i++) {
			if (bit & (1 << i)) op[i] = '+';
		}
		if (op[0] == '+') seven += a + b;
		else seven += a - b;
		if (op[1] == '+') seven += c;
		else seven -= c;
		if (op[2] == '+') seven += d;
		else seven -= d;
		if (seven == 7) break;
	}

	cout << a << op[0] << b << op[1] << c << op[2] << d << "=7" << endl;

	return 0;
}