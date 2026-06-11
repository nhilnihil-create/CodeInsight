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

	for (long long i = 0; i < n; i++)
	{
		std::cin >> v[i];
	}

	long long ans = 0;

	for (long long i = 0; i < n; i++)
	{
		while (v[i] > 0) {
			for (long long j = i; j < n && v[j] > 0; j++)
			{
				v[j]--;
			}
			ans++;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
