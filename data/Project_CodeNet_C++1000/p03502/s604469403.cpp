#include <iostream>
using namespace std;


int main()
{
	int N = 0, L = 0, M = 0, ans = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	cin >> N;

	for (int i = 0; i < 8; i++) {
		a = N % 10;
		b = N % 100 / 10;
		c = N % 1000 / 100;
		d = N % 10000 / 1000;
		e = N % 100000 / 10000;
		f = N % 1000000 / 100000;
		g = N % 10000000 / 1000000;
		h = N % 100000000 / 10000000;
		M = a + b + c + d + e + f + g + h;
		L = N % M;
	}

	if (0 < L) {
		cout << "No" << endl;
	}

	else
		cout << "Yes" << endl;
    
}