#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	int a, b, c, d;
	a = N % 10;
	b = (N % 100 - a) / 10;
	c = (N % 1000 - (a + b)) / 100;
	d = N / 1000;
	//cout << d << c << b << a << endl;

	if (((a == b) && (a == c) && (b == c)) ||
		((b == c) && (b == d) && (c == d))) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}