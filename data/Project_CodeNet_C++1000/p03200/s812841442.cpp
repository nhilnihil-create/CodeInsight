#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
#include <numeric>
#include <functional>
#include <stack>
#include <iomanip>
#include <map>
#include <cstdio>


int main() {

	std::string s;

	std::cin >> s;

	long long black = 0;
	long long ans = 0;

	for (long long i = 0; i < s.length(); i++)
	{
		if (s[i] == 'B') {
			black++;
		}
		else {
			ans += black;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
