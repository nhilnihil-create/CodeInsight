#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

template <class T>
auto Input()
{
	T t;
	std::cin >> t;
	return t;
}

template <class T>
auto Input(int n)
{
	T v(n);
	for (auto &e : v) std::cin >> e;
	return v;
}


int main()
{
	auto s = Input<std::string>();
	
	int max = 0;
	int cnt = 0;
	for (char c : s) {
		if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
			cnt++;
		}
		else {
			max = std::max(cnt, max);
			cnt = 0;
		}
	}
	
	std::cout << std::max(cnt, max) << std::endl;
	
	return 0;
}
