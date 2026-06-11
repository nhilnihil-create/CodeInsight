#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	std::string s; std::cin >> s;
	int count = 0; int count2 = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] - '0' == i % 2) ++count;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] - '0' != i % 2) ++count2;
	std::cout << std::min(count, count2) << std::endl;

	return 0;
}