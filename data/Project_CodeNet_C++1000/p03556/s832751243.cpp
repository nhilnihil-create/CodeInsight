#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = n; i >= 0; i--) {
		int x = sqrt(i);
		if (x * x == i) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}
