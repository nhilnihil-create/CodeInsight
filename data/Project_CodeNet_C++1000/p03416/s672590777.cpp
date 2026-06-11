#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	int a, b; std::cin >> a >> b;
	int count = 0;
	for (int i = a; i <= b; ++i) {
		std::string s = std::to_string(i);
		std::string cp = s;
		std::reverse(cp.begin(), cp.end());
		if (cp == s) ++count;
	}
	std::cout << count << std::endl;

	return 0;
}