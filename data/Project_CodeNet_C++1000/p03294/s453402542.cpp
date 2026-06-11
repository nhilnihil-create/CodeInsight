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

	long long n;

	std::cin >> n;

	std::vector<long long> v(n);
	long long ans = 0;

	for (long long i = 0; i < n; i++)
	{
		std::cin >> v[i];
		ans += v[i] - 1;
	}

	std::cout << ans << std::endl;

	return 0;
}
