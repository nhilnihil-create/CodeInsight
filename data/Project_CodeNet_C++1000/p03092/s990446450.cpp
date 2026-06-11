#include <bits/stdc++.h>
using namespace std;

namespace TYC
{
	typedef long long ll;
	const int N = 5005;

	int n, A, B, P[N];
	ll F[N];

	void work()
	{
		scanf("%d%d%d", &n, &A, &B);
		for (int i = 1; i <= n; i++)
			scanf("%d", &P[i]);
		P[n + 1] = n + 1;
		memset(F, 0x3f, sizeof(F));
		F[0] = 0;
		for (int i = 1; i <= n + 1; i++)
		{
			int cnt[2] = {0, 0};
			if (P[i - 1] < P[i])
				F[i] = F[i - 1];
			for (int j = i - 1; j; j--)
			{
				cnt[P[j] < P[i]]++;
				if (P[j - 1] < P[i])
					F[i] = min(F[i], F[j - 1] + (ll)cnt[0] * A + (ll)cnt[1] * B);
			}
		}
		printf("%lld\n", F[n + 1]);
	}
}

int main()
{
	TYC::work();
	return 0;
}