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

	std::string s;

	std::cin >> s;

	int red = std::count(s.begin(), s.end(), 'R');
	int blue = s.length() - red;

	if (red > blue) {
		std::cout << "Yes" << std::endl;
	}
	else {
		std::cout << "No" << std::endl;
	}

	return 0;
}