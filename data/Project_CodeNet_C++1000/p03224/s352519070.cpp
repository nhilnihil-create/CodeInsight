#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL N;
	in >> N;

	if (N * 2 != (LL)sqrt(N * 2)*((LL)sqrt(N * 2) + 1))
	{
		out << "No" << std::endl;
		return 0;
	}
	if (N == 1)
	{
		out << "Yes" << std::endl << 2 << std::endl << 1 << " " << 1 << std::endl << 1 << " " << 1 << std::endl;
		return 0;
	}

	LL size = sqrt(N * 2);
	std::vector<std::vector<LL>>field(size);
	LL num = 1;
	rep(i, size)
	{
		rep(j, i + 1)
		{
			field[i].push_back(num);
			++num;
		}
	}

	std::vector<std::vector<LL>>ans(size + 1);
	rep(i, size)
	{
		ans[0].push_back(field[i][0]);
		ans[1].push_back(field[size - 1][i]);
		ans[2].push_back(field[i][i]);
	}
	rep(i, size - 2)
	{
		rep(j, i + 1) ans[i + 3].push_back(field[i + 1][j]);
		rep(j, size - i - 1) ans[i + 3].push_back(field[i + 1 + j][i + 1]);
	}

	out << "Yes" << std::endl << ans.size() << std::endl;
	rep(i, ans.size())
	{
		out << ans[i].size() << " ";
		rep(j, ans[i].size()) out << ans[i][j] << (j < ans[i].size() - 1 ? " " : "\n");
	}
	return 0;
}
