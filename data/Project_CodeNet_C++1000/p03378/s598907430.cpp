#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

int main()
{
	int n, m, x;
	std::cin >> n >> m >> x;
	
	int left, right;
	left = right = 0;
	int a;
	for (int i = 0; i < m; i++) {
		std::cin >> a;
		(*(x < a ? &left : &right))++;
	}
	
	std::cout << std::min(left, right) << std::endl;
	
	return 0;
}
