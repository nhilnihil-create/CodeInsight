#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <math.h>
#include <queue>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
	int ABCDE[5];
	int minIndex = 0;
	int minValue = 9;

	for (int i = 0; i < 5; ++i) {
		cin >> ABCDE[i];

		int val = ABCDE[i] % 10;
		if (val > 0) {
			if (minValue > val) {
				minValue = val;
				minIndex = i;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 5; ++i) {
		if (i != minIndex) {
			if (ABCDE[i] % 10 > 0) {
				ABCDE[i] = (ABCDE[i] / 10) * 10 + 10;
			}
		}
		ans += ABCDE[i];
	}
	cout << ans << endl;

	return 0;
}
