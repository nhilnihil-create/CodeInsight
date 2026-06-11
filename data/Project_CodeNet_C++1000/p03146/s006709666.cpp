#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int s; std::cin >> s;
	std::vector<int> Check;
	bool flag = false;
	int count = 0;
	while (flag == false) {
		Check.push_back(s);
		++count;
		if (s % 2 == 0)
			s = s / 2;
		else
			s = s * 3 + 1;
		for (int i = 0; i < Check.size(); ++i)
			if (s == Check[i]) {
				flag = true;
				break;
			}
	}
	std::cout << count + 1 << std::endl;

	return 0;
}