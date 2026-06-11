#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int T, X;
	cin >> T >> X;
	double time = T * 1.0 / X;
	cout << fixed << setprecision(3) << time << endl;
	return 0;
}