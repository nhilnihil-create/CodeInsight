#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL N, seek;

int main()
{
	in >> N;
	if (N == 3)
	{
		out << 2 << " " << 3 << " " << 25 << std::endl;
		return 0;
	}
	std::vector<LL>ans, even({ 2,4,3,9,6,12,8,10 }), odd({ 6,2,4,3,9,10,8,12 });
	rep(i, N)
	{
		if (N % 2)
		{
			ans.push_back(odd[seek]);
			odd[seek] += 12;
		}
		else
		{
			ans.push_back(even[seek]);
			even[seek] += 12;
		}
		++seek;
		seek %= 8;
	}
	rep(i, ans.size()) out << ans[i] << (i < ans.size() - 1 ? " " : "\n");
	return 0;
}
