#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL K;
std::vector<LL>ans;

LL f(LL n)
{
	LL res = 0;
	while (n > 0)
	{
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main()
{
	in >> K;
	for (LL i = 0; i <= 15; ++i)
	{
		for (LL j = 1; j <= 1000; ++j)
		{
			if (i == 0 && j == 1) continue;
			LL tmp = j * pow(10LL, i);
			--tmp;
			ans.push_back(tmp);
		}
	}
	std::sort(ans.begin(), ans.end());
	ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
	rep(i, ans.size())
	{
		for (int j = i + 1; j < ans.size(); ++j)
		{
			if ((long double)ans[i] / f(ans[i]) > (long double)ans[j] / f(ans[j]))
			{
				ans.erase(ans.begin() + i);
				--i;
				break;
			}
		}
	}
	rep(i, K) out << ans[i] << std::endl;
	return 0;
}
