#include <iostream>
#include <string>

int main()
{
	std::string s;
	int head;
	int tail;
	std::cin >> s;
	head = std::stoi(s.substr(0, 2));
	tail = std::stoi(s.substr(2, 2));
	
	if (head < 1 || head > 12)
	{
		if (tail >= 1 && tail <= 12)
			std::cout << "YYMM\n";
		else
			std::cout << "NA\n";
	}
	else if (tail < 1 || tail > 12)
		std::cout << "MMYY\n";
	else
		std::cout << "AMBIGUOUS\n";
}
