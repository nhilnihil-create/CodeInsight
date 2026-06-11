#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950



int main() {
	std::string s; std::cin >> s;
	std::vector<long long> NUM(s.size() - 2);
	for (int i = 0; i < s.size() - 2; ++i)
		NUM[i] = ((s[i] - '0') * 100) + ((s[i + 1] - '0') * 10) + (s[i + 2] - '0');
	long long d = 100000000000;
	for (int i = 0; i < NUM.size(); ++i) {
		if (d > std::abs(753 - NUM[i]))
			d = std::abs(753 - NUM[i]);
	}
	std::cout << d << std::endl;

	return 0;
}