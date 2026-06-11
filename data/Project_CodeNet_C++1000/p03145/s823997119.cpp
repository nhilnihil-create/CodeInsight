#include <iostream>
#include <math.h>

using namespace std;

main() {
	ios::sync_with_stdio(false);

	int ab, bc, ca;
	cin >> ab >> bc >> ca;

	int p;
	p = (ab + bc + ca) / 2;

	int area;
	area = sqrt(p * (p - ab) * (p - bc) * (p - ca));
	cout << area << endl;

	return 0;
}