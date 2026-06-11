#include <iostream>

int main()
{
	int a, b;
	std::string s;
	std::cin >> a >> b >> s;
	
	if (s[a] != '-') {
		std::cout << "No" << std::endl;
		return 0;
	}
	s.erase(s.begin() + a);
	for (char c : s) {
		if (c < '0' || c > '9') {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
	
	std::cout << "Yes" << std::endl;
	return 0;
}
