#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main() {
	int a, b, c, d, x, y;
	cin >> a >> b >> c >> d;
	if (a >= b)
		x = b;
	else
		x = a;
	if (c >= d)
		y = d;
	else
		y = c;
	cout << x + y << "\n";
}