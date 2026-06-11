#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::unordered_map<int, int> mapa;
	mapa.insert(std::make_pair(0, 0));
	std::string str;
	std::getline(std::cin, str);
	
	int n = str.length();
	int xoring = 0;
	
	for (int i = 0; i < n; ++i)
	{
		int place = str[i] - 'a';
		xoring ^= (1 << place);
		int min = i + 1;
		
		if (mapa.count(xoring))
		{
			min = std::min(min, mapa[xoring] + 1);
		}
		
		for (int j = 0; j < 26; ++j)
		{
			if (mapa.count(xoring ^ (1 << j)))
			{
				min = std::min(min, mapa[xoring ^ (1 << j)] + 1);
			}
		}
		
		if (mapa.count(xoring))
			mapa[xoring] = std::min(mapa[xoring], min);
		else
			mapa[xoring] = min;
		
		if (i == n - 1)
			std::cout << min;
	}
}