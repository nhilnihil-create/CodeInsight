#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <map>
#include <cstdio>

int main() {
	long long a, b, c, k;

	std::cin >> a >> b >> c >> k;

	if (k % 2 == 0) {
		std::cout << a - b << std::endl;
	}
	else {
		std::cout << b - a << std::endl;
	}

	return 0;
}