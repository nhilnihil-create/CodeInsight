#include <bits/stdc++.h>

int N;
std::string S;
std::vector<int> Mtable;

int64_t solve();

int main()
{
	scanf("%d", &N);
	std::cin >> S;
	Mtable.resize(N + 1);
	for (int i{N - 1}; i >= 0; i--)
	{
		if (S[i] == 'M') Mtable[i]++;
		Mtable[i] += Mtable[i + 1];
	}
	int Q;
	scanf("%d", &Q);
	for (int i{}; i < Q; i++)
		printf("%lld\n", solve());

	return 0;
}

int64_t solve()
{
	int k;
	scanf("%d", &k);

	int64_t ans{}, count{}, sum{};
	for (int i{N - 1}; i >= 0; i--)
	{
		if (i + k < N && S[i + k] == 'C')
		{
			count--;
			sum -= Mtable[i + 1] - Mtable[i + k];
		}
		if (S[i] == 'D')
			ans += sum;
		else if (S[i] == 'M')
			sum += count;
		else if (S[i] == 'C')
			count++;
	}
	return ans;
}