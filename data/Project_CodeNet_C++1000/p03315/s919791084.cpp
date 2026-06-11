#include <stdio.h>
#include <iostream>

int main() 
{
	std::string s;
	std::cin >> s;
	int k = 0;

	for (int i = 0 ; i < 4 ; i++) {
		if (s[i] == '+') {
			++k;
		}
		else {
			--k;
		}
	}

	std::cout << k << std::endl;
	return 0;
}