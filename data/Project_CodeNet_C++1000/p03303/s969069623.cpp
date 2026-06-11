#include <bits/stdc++.h>

int main()
{
	std::string S;
	int w;
	std::cin >> S >> w;
	for (int i{}; i < (int)S.size(); i += w) putchar(S[i]);
	putchar('\n');

	return 0;
}