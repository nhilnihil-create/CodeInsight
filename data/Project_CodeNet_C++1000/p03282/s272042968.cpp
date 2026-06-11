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
	std::string s;
	long long k;

	std::cin >> s >> k;

	if (k == 1) {
		std::cout << s[0] << std::endl;
		return 0;
	}

	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] != '1' || i == k - 1) {
			std::cout << s[i] << std::endl;
			return 0;
		}
	}

	return 0;
}
