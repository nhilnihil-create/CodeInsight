#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

int main()
{
	LL N;
	in >> N;
	std::vector<LL>a(N), b(N);
	rep(i, N) in >> a[i];
	rep(i, N) in >> b[i];

	LL ans = 0;
	rep(k, 30)
	{
		auto a_ = a, b_ = b;
		LL modL = (1LL << (k + 1)), modS = (1LL << k);
		rep(i, N)
		{
			a[i] %= modL;
			b[i] %= modL;
		}
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());
		LL cnt = 0;
		rep(i, N)
		{
			auto it1 = std::lower_bound(b.begin(), b.end(), 2 * modS - a[i]);
			auto it2 = std::lower_bound(b.begin(), b.end(), modS - a[i]);
			auto it3 = std::lower_bound(b.begin(), b.end(), 4 * modS - a[i]);
			auto it4 = std::lower_bound(b.begin(), b.end(), 3 * modS - a[i]);
			cnt += (it1 - it2) + (it3 - it4);
		}
		if (cnt % 2 == 1) ans += (1LL << k);
		a = a_, b = b_;
	}

	out << ans << std::endl;
	return 0;
}
