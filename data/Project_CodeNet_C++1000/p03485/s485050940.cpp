#include "bits/stdc++.h"
using namespace std;

int main()
{
	float x;
	int a, b, c;
	cin >> a >> b;

	x = (a + b) / 2.;
	c = int(x);

	if (x > c) {
		c = c + 1;
	}
	cout << c << endl;
}