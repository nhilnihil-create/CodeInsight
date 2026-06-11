#include <iostream>
#include <map>

int f(int n)
{
	return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

int main()
{
	int s;
	std::cin >> s;
	
	std::map<int, int> mp;
	int i;
	for (i = 1; i <= 1000000; i++) {
		if (mp.count(s)) {
			break;
		}
		mp[s];
		s = f(s);
	}
	
	std::cout << i << std::endl;
	
	return 0;
}
