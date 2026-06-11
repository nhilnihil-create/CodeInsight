#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

int main()
{
	std::vector<int>a(3), b(3);
	rep(i, 3) in >> a[i] >> b[i];

	std::vector<int>cnt(5);
	rep(i, 3)
	{
		++cnt[a[i]];
		++cnt[b[i]];
	}
	out << ((cnt[1] > 2 || cnt[2] > 2 || cnt[3] > 2 || cnt[4] > 2) ? "NO" : "YES") << std::endl;
}
