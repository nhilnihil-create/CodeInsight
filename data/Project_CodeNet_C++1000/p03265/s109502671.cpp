#include <iostream>
using namespace std;

int main() {
	int x[4];
	int y[4];
	for (int i = 0; i < 2; i++) {
		cin >> x[i] >> y[i];
	}


	int xa = x[1] - x[0];
	int ya = y[1] - y[0];

	x[2] = x[1] - ya;
	y[2] = y[1] + xa;

	x[3] = x[2] - xa;
	y[3] = y[2] - ya;

	cout << x[2]  << " " << y[2] << " "  << x[3] << " " << y[3] <<"\n";
	return 0;
}