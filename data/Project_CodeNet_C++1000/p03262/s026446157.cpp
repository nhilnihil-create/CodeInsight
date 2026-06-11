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

long long gcd(long long a, long long b)
{
	if (a % b == 0)
	{
		return(b);
	}
	else
	{
		return(gcd(b, a % b));
	}
}

int main() {
	long long n, x;

	std::cin >> n >> x;

	std::vector<long long> v(n);

	for (long long i = 0; i < n; i++)
	{
		std::cin >> v[i];
		v[i] = std::abs(x - v[i]);
	}

	if (n == 1) {
		std::cout << v[0] << std::endl;
		return 0;
	}

	long long ans = gcd(v[0], v[1]);

	for (long long i = 2; i < n; i++)
	{
		ans = gcd(ans, v[i]);
	}

	std::cout << ans << std::endl;


	return 0;
}
