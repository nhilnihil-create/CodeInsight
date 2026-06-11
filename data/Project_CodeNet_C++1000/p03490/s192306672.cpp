#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

std::string s;
int x, y, memo[8001][16002];
std::vector<int>dx, dy;

int dp1(int k, int px)
{
	if (k == dx.size()) return (px == x ? 0 : 1);
	if (memo[k][px + 8001] != -1) return memo[k][px];
	auto res1 = dp1(k + 1, px + dx[k]);
	auto res2 = dp1(k + 1, px - dx[k]);
	return memo[k][px + 8001] = ((res1 == 0 || res2 == 0) ? 0 : 1);
}
int dp2(int k, int py)
{
	if (k == dy.size()) return (py == y ? 0 : 1);
	if (memo[k][py + 8001] != -1) return memo[k][py];
	auto res1 = dp2(k + 1, py + dy[k]);
	auto res2 = dp2(k + 1, py - dy[k]);
	return memo[k][py + 8001] = ((res1 == 0 || res2 == 0) ? 0 : 1);
}

int main()
{
	in >> s >> x >> y;
	int start = 0, cou = 0;
	rep(i, s.length())
	{
		if (s[i] == 'T')
		{
			if (cou % 2 == 0) dx.push_back(i - start);
			else dy.push_back(i - start);
			start = i + 1;
			++cou;
		}
		else if (i == s.length() - 1)
		{
			if (cou % 2 == 0) dx.push_back(i - start + 1);
			else dy.push_back(i - start + 1);
			break;
		}
	}
	memset(memo, -1, sizeof(memo));
	auto ans1 = dp1(1, dx[0]);
	memset(memo, -1, sizeof(memo));
	auto ans2 = dp2(0, 0);
	out << ((ans1 == 0 && ans2 == 0) ? "Yes" : "No") << std::endl;
	return 0;
}
