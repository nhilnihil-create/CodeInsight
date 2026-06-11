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
	long long a, b;

	std::cin >> a >> b;

	std::vector<std::string> v(a);

	for (long long i = 0; i < a; i++)
	{
		std::cin >> v[i];
	}

	long long x[] = { 1, 0, -1, 0 };
	long long y[] = { 0, 1, 0 , -1};

	for (long long i = 0; i < a; i++)
	{
		for (long long j = 0; j < b; j++)
		{
			bool flag = false;
			if (v[i][j] == '#') {
				for (long long k = 0; k < 4; k++)
				{
					long long xx = i + x[k];
					long long yy = j + y[k];

					if (xx >= 0 && yy >= 0 && xx < a && yy < b) {
						if (v[xx][yy] == '#') {
							flag = true;
							break;
						}
					}
				}
				if (flag == false) {
					std::cout << "No" << std::endl;
					return 0;
				}

			}
		}
	}

	std::cout << "Yes" << std::endl;

	return 0;
}
