#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

int main()
{
	int A, B;
	in >> A >> B;

	std::vector<std::vector<char>>ans(100, std::vector<char>(100));
	rep(i, 100) rep(j, 100) ans[i][j] = (i < 50 ? '#' : '.');
	--A; --B;
	for (int i = 1; i < 50; i += 2)
	{
		bool flag = true;
		for (int j = 1; j < 100; j += 2)
		{
			if (A == 0)
			{
				flag = false;
				break;
			}
			ans[i][j] = '.';
			--A;
		}
		if (!flag) break;
	}
	for (int i = 51; i < 100; i += 2)
	{
		bool flag = true;
		for (int j = 1; j < 100; j += 2)
		{
			if (B == 0)
			{
				flag = false;
				break;
			}
			ans[i][j] = '#';
			--B;
		}
		if (!flag) break;
	}

	out << 100 << " " << 100 << std::endl;
	rep(i, 100)
	{
		rep(j, 100) out << ans[i][j];
		out << std::endl;
	}
	return 0;
}
