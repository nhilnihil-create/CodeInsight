#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::string s; std::cin >> s;
	int count{ 0 };
	int ans{ 0 };
	for (auto i{ 0 }; i < s.size(); ++i) {
		if (s[i] == 'T' || s[i] == 'A' || s[i] == 'C' || s[i] == 'G') {
			++count;
			if (ans < count) ans = count;
		}
		else {
			if (ans < count) ans = count;
			count = 0;
		}
	}
	std::cout << ans << std::endl;

	return 0;
}
