#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

LL N, Q;
std::string s;
std::vector<char>t, d;

bool check1(LL p)
{
	rep(i, Q)
	{
		if (s[p] == t[i])
		{
			if (d[i] == 'L') --p;
			else ++p;
		}
		if (p < 0) return true;
		if (p >= N) return false;
	}
	return false;
}

bool check2(LL p)
{
	rep(i, Q)
	{
		if (s[p] == t[i])
		{
			if (d[i] == 'L') --p;
			else ++p;
		}
		if (p < 0) return false;
		if (p >= N) return true;
	}
	return false;
}

int main()
{
	in >> N >> Q >> s;
	t.resize(Q); d.resize(Q);
	rep(i, Q) in >> t[i] >> d[i];

	LL left1 = 0, right1 = N + 1;
	while (right1 - left1 > 1)
	{
		LL mid = (left1 + right1) / 2;
		if (check1(mid)) left1 = mid;
		else right1 = mid;
	}

	LL left2 = -1, right2 = N;
	while (right2 - left2 > 1)
	{
		LL mid = (left2 + right2) / 2;
		if (check2(mid)) right2 = mid;
		else left2 = mid;
	}

	out << std::max<LL>(left2 - right1 + 1, 0) << std::endl;
}
