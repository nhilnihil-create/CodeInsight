#include "bits/stdc++.h"

typedef long long ll;

typedef long double ld;

int main()
{
	int x[2], y[2];
	for (int i = 0; i < 2; ++i)
	{
		std::cin >> x[i] >> y[i];
	}
	int dx = x[1] - x[0];
	int dy = y[1] - y[0];
	std::cout << x[1] - dy << ' ' << y[1] + dx << ' ';
	std::cout << x[0] - dy << ' ' << y[0] + dx << '\n';
	return 0;
}