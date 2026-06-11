#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950



int main() {
	long long N; std::cin >> N;
	std::vector<long long> A(N);
	long long count = 0;
	long long min = 10000000000;
	for (auto& r : A) {
		count = 0;
		std::cin >> r;
		while(true){
			if (r % 2 == 1)
				break;
			++count;
			r /= 2;
		}
		if (count < min)min = count;
	}
	std::cout << min << std::endl;

	return 0;
}