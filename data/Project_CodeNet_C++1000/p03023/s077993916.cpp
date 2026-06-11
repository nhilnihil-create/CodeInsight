#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <numeric>

int main() {
	int n;

	std::cin >> n;

	long long ans = 180;

	for (size_t i = 3; i < n; i++)
	{
		ans += 180;
	}

	std::cout << ans << std::endl;

	return 0;
}