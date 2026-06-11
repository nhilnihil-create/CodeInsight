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
	intt N = s.size();
	intt count = 0;
	intt num = 0;
	for (int i = 0; i < N; ++i) {
		if (s[i] == 'W') {
			count += num;
		}
		else
			++num;
	}
	std::cout << count << std::endl;

}