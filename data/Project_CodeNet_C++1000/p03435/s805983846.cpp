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
	std::vector<intt> c(9);
	for (auto& r : c) std::cin >> r;
	if(((c[0]-c[1] != c[3] -c[4])
		||(c[0] - c[1]!= c[6] - c[7])
		||(c[6] - c[7]!= c[3] - c[4]))
		||
		((c[1] - c[2] != c[4] - c[5])
			|| (c[1] - c[2] != c[7] - c[8])
			|| (c[7] - c[8] != c[4] - c[5]))
		||
		((c[0] - c[3] != c[1] - c[4])
			|| (c[2] - c[5] != c[0] - c[3])
			|| (c[2] - c[5] != c[1] - c[4]))
		||
		((c[3] - c[6] != c[4] - c[7])
			|| (c[3] - c[6] != c[5] - c[8])
			|| (c[5] - c[8] != c[4] - c[7]))){
		std::cout << "No" << std::endl;
		return 0;
	}
	std::cout << "Yes" << std::endl;
	return 0;
}