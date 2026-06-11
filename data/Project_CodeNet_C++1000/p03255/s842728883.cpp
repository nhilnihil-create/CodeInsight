#include <bits/stdc++.h>

int main()
{
	int N;
	long long X;
	scanf("%d%lld", &N, &X);
	std::vector<long long> x(N + 1);
	for (int i{1}; i <= N; i++)
	{
		scanf("%lld", &x[i]);
		x[i] += x[i - 1];
	}
	
	long long min{1LL << 60};
	// turnを1<= turn <=nで固定
	for (int turn{1}; turn <= N; turn++)
	{
		// 往復そのものに必要なエネルギー、拾うのと捨てるのに必要なエネルギー、2k+1の1のエネルギー
		long long sum{2 * (x[N] - x[N - turn]) + (N + turn) * X + x[N]};
		int k;
		for (k = 1; N - k * turn >= 0; k++)
		{
			sum += 2 * k * (x[N - (k - 1) * turn] - x[N - k * turn]);
			if (sum > min) break;
		}
		if (sum > min) continue;
		sum += 2 * k * x[N - (k - 1) * turn];
		min = std::min(min, sum);
	}
	printf("%lld\n", min);

	return 0;
}