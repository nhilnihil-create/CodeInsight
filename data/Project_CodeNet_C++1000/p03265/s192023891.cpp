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

	if (dx > 0) a = true;
	if (dy > 0) b = true;

	dx = abs(dx);
	dy = abs(dy);


	if (a && b) {
		x[2] = x[1] - dy, x[3] = x[2] - dx, y[2] = y[1] + dx, y[3] = y[2] - dy;
	}
	else if(a && !b) {
		x[2] = x[1] + dy, x[3] = x[2] - dx, y[2] = y[1] + dx, y[3] = y[2] + dy;
	}
	else if (!a && b) {
		x[2] = x[1] - dy, x[3] = x[2] + dx, y[2] = y[1] - dx, y[3] = y[2] - dy;
	}
	else if (!a && !b) {
		x[2] = x[1] + dy, x[3] = x[2] + dx, y[2] = y[1] - dx, y[3] = y[2] + dy;
	}

	cout << x[2] << " " << y[2] << " " << x[3] << " " << y[3];

	return 0;

}