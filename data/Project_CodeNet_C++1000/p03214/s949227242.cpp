#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int> a(N);
	for (auto& e: a) scanf("%d", &e);
	int sum{};
	for (auto& e: a) sum += e;
	int ans{};
	for (int i{}; i < N; i++)
		if (std::abs(a[i] * N - sum) < std::abs(a[ans] * N - sum))
			ans = i;
	printf("%d\n", ans);

	return 0;
}