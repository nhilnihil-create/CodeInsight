#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	int r, D;
	vector<int> x(11);
	cin >> r >> D >> x[0];
	for (int i = 0; i < 10; i++) {
		x[i + 1] = r * x[i] - D;
		cout << x[i + 1] << endl;
	}
	return 0;
}