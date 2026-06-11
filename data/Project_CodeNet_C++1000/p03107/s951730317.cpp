#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	std::string s; std::cin >> s;
	int count0 = 0;
	int count1 = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0')++count0;
		else if (s[i] == '1') ++count1;
	}
	std::cout << s.size() - std::abs(count0 - count1) << std::endl;

	return 0;
}
