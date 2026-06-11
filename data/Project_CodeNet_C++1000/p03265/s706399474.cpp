#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

	int x[4], y[4], dx ,dy;
	bool a = false, b = false;

	cin >> x[0] >> y[0] >> x[1] >> y[1];

	dx = x[1] - x[0];
	dy = y[1] - y[0];


	cout << x[1] - dy << " " << y[1] + dx << " " << x[1] -dy - dx << " " << y[1] + dx - dy;

	return 0;

}