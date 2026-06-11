#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <numeric>

int main() {
	std::string s;

	std::cin >> s;

	int lose = std::count(s.begin(), s.end(), 'x');

	if (15 - lose >= 8 ) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}

	return 0;
}