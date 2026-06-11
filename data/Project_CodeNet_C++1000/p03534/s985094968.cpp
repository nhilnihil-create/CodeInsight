#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

std::string S;
int couA, couB, couC;

int main()
{
	in >> S;

	for (auto c : S)
	{
		if (c == 'a') { ++couA; }
		if (c == 'b') { ++couB; }
		if (c == 'c') { ++couC; }
	}
	if (abs(couA - couB) <= 1 && abs(couB - couC) <= 1 && abs(couA - couC) <= 1)
	{
		out << "YES" << std::endl;
	}
	else { out << "NO" << std::endl; }
	return 0;
}