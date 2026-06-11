#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

int main() {

	int x[5], y[5];
	x[0] = 0;
	y[0] = 0;
	cin >> x[1] >> y[1] >> x[2] >> y[2];

	x[3] = y[1] - y[2] + x[2];
	y[3] = -x[1] + x[2] + y[2];
	x[4] = -y[2] + y[1] + x[1];
	y[4] = x[2] - x[1] + y[1];

	cout << x[3] << " " << y[3] << " " << x[4] << " " << y[4];

	return 0;
}

