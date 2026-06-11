#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	std::string s; std::cin >> s;
	for (int i = 1; i < s.size() - 2; ++i) {
		for (int j = i; j < s.size(); ++j){
			if (s.substr(0, i) + s.substr(j, s.size() - 1) == "keyence") {
				std::cout << "YES" << std::endl;
				return 0;
			}
		}
	}
	std::cout << "NO" << std::endl;
	return 0;
}