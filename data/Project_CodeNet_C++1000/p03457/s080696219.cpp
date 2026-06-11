#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>


using namespace std;


int main() {

	bool ans = true;

	long long int N, t, x, y, t0 = 0, x0 = 0, y0 = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> t >> x >> y;
		
		if (t % 2 != (x + y) % 2) {
			ans = false;
		}
		else if (t < x + y) {
			ans = false;
		}
		else if (t - t0 < abs(x - x0) + abs(y - y0)) {
			ans = false;
		}
		t0 = t;
		x0 = x;
		y0 = y;
	}

	if (ans) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}
