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

int main() {
	std::string s;

	std::cin >> s;

	std::string ans[] = { "AKIHABARA", "AKIHABAR", "AKIHABRA", "AKIHABR", "AKIHBARA", "AKIHBAR", "AKIHBRA", "AKIHBR", "KIHABARA", "KIHABAR", "KIHABRA", "KIHABR", "KIHBARA", "KIHBAR", "KIHBRA", "KIHBR" };

	int pos = 0, pos2 = 0;

	for (auto& a : ans) {
		if (a == s) {
			std::cout << "YES" << std::endl;
			return 0;
		}
	}

	std::cout << "NO" << std::endl;

	return 0;
}
