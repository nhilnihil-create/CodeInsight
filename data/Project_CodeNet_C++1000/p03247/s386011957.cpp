#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;

LL N, M;
std::vector<LL>d;

int main()
{
	in >> N;
	std::vector<LL>X(N), Y(N);
	rep(i, N)
	{
		in >> X[i] >> Y[i];
		if ((llabs(X[i]) + llabs(Y[i])) % 2 != (llabs(X[0]) + llabs(Y[0])) % 2)
		{
			out << -1 << std::endl;
			return 0;
		}
	}
	M = 33;
	rep(i, M) d.push_back(1LL << (M - i - 1));
	if ((llabs(X[0]) + llabs(Y[0])) % 2 == 0)
	{
		++M;
		d.push_back(1);
	}
	out << M << std::endl;
	rep(i, M) out << d[i] << (i < M - 1 ? " " : "\n");
	rep(i, N)
	{
		LL px = 0, py = 0;
		std::string ans;
		rep(j, M)
		{
			LL dx = X[i] - px, dy = Y[i] - py;
			if (llabs(dx) >= llabs(dy))
			{
				if (dx >= 0)
				{
					ans += "R";
					px += d[j];
				}
				else
				{
					ans += "L";
					px -= d[j];
				}
			}
			else
			{
				if (dy >= 0)
				{
					ans += "U";
					py += d[j];
				}
				else
				{
					ans += "D";
					py -= d[j];
				}
			}
		}
		out << ans << std::endl;
	}
	return 0;
}
