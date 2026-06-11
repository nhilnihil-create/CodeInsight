#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <numeric>


int main() {
	int n, z, w;

	std::cin >> n >> z >> w;

	std::vector<int> v(n);

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}

	if (n == 1) {
		std::cout << abs(v[0] - w) << std::endl;
		return 0;
	}

	std::cout << std::max(abs(v[n - 1] - w), abs(v[n - 2] - v[n - 1])) << std::endl;

	return 0;
}