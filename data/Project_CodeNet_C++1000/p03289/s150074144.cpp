#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

bool check_small(char& a) {
	if ('a' <= a && a <= 'z')
		return true;
	return false;
}

int main(){
	std::string s; std::cin >> s;
	if (s[0] != 'A') {
		std::cout << "WA" << std::endl;
		return 0;
	}
	int count = 0;
	int p = 0;
	for (int i = 2; i < s.size() - 1; ++i) {
		if (s[i] == 'C') {
			++count;
			p = i;
		}
	}
	if (count != 1) {
		std::cout << "WA" << std::endl;
		return 0;
	}

	for (int i = 0; i < s.size(); ++i) {
		if (i == 0) continue;
		else if(i == p) continue;
		else {
			if (check_small(s[i]) == false) {
				std::cout << "WA" << std::endl;
				return 0;
			}
		}
	}
	std::cout << "AC" << std::endl;
	return 0;
}