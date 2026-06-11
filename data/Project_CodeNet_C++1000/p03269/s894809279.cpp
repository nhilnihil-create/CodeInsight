#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL L, N;
std::vector<std::pair<std::pair<LL, LL>, LL>>paths;

int main()
{
	in >> L;
	LL temp = L;
	while (temp > 0)
	{
		temp /= 2;
		++N;
	}
	rep(i, N - 1)
	{
		paths.push_back(std::make_pair(std::make_pair(i + 1, i + 2), 0));
		paths.push_back(std::make_pair(std::make_pair(i + 1, i + 2), (1LL << i)));
	}
	for (LL r = N - 1; r >= 1; --r)
	{
		if ((1LL << (N - 1)) + (1LL << (r - 1)) <= L)
		{
			paths.push_back(std::make_pair(std::make_pair(r, N), L - (1LL << (r - 1))));
			L -= (1LL << (r - 1));
		}
	}
	out << N << " " << paths.size() << std::endl;
	for (auto path : paths) out << path.first.first << " " << path.first.second << " " << path.second << std::endl;
	return 0;
}
