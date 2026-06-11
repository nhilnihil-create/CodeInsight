#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <climits>
#include <memory>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
	long long n, p;

	cin >> n >> p;

	long long a = pow(p, (1.0/n)) + 1;
	
	for (; a >= 1; a--) {
		if (p % (long long)pow(a, n) == 0) break;
	}

	cout << a << endl;

	return 0;
}