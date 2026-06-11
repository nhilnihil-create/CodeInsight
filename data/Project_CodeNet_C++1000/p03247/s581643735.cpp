#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;

	const int N = 1003;
	const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
	const char CH[] = {'R', 'L', 'U', 'D'};

	int n, dc;
	ll X[N], Y[N], D[N], S[N];
	char R[N];

	inline bool check(const ll x, const ll y, const int i)
	{
		return abs(x) + abs(y) <= S[i];
	}

	void work()
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld%lld", &X[i], &Y[i]);
			if (i != 1 && ((X[i] + Y[i]) & 1) != ((X[1] + Y[1]) & 1))
				return void(puts("-1"));
		}
		if (!((X[1] + Y[1]) & 1))
			D[++dc] = 1;
		for (int i = 0; i <= 30; i++)
			D[++dc] = 1LL << i;
		printf("%d\n", dc);
		for (int i = 1; i <= dc; i++)
		{
			printf("%lld ", D[i]);
			S[i] = S[i - 1] + D[i];
		}
		puts("");
		for (int i = 1; i <= n; i++)
		{
			ll x = X[i], y = Y[i];
			for (int j = dc; j; j--)
				for (int k = 0; k < 4; k++)
				{
					ll tx = x + dx[k] * D[j], ty = y + dy[k] * D[j];
					if (check(tx, ty, j - 1))
					{
						R[j] = CH[k];
						x = tx, y = ty;
						break;
					}
				}
			puts(R + 1);
		}
	}
}

int main()
{
	TYC::work();
	return 0;
}