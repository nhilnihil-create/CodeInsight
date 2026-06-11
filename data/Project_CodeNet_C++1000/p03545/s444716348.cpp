#include <iostream>

using namespace std;

int main() {
	string abcd;
	cin >> abcd;
	int a = abcd[0] - '0', b = abcd[1] - '0', c = abcd[2] - '0', d = abcd[3] - '0';
	if (a + b + c + d == 7) { cout << a << "+" << b << "+" << c << "+" << d << "=7"; return 0; }
	if (a + b + c - d == 7) { cout << a << "+" << b << "+" << c << "-" << d << "=7"; return 0; }
	if (a + b - c + d == 7) { cout << a << "+" << b << "-" << c << "+" << d << "=7"; return 0; }
	if (a + b - c - d == 7) { cout << a << "+" << b << "-" << c << "-" << d << "=7"; return 0; }
	if (a - b + c + d == 7) { cout << a << "-" << b << "+" << c << "+" << d << "=7"; return 0; }
	if (a - b + c - d == 7) { cout << a << "-" << b << "+" << c << "-" << d << "=7"; return 0; }
	if (a - b - c + d == 7) { cout << a << "-" << b << "-" << c << "+" << d << "=7"; return 0; }
	if (a - b - c - d == 7) { cout << a << "-" << b << "-" << c << "-" << d << "=7"; return 0; }
}