#include <bits/stdc++.h>

int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	if (a + b - n >= 2 || (long long)a * b < n)
	{
		puts("-1");
		return 0;
	}
	int lds{};
	if (b > 1) lds = (n - a) / (b - 1);
	int rest{n - a - lds * (b - 1)};
	std::vector<int> ans;
	for (int i{}; i < lds; i++)
		for (int j{(i + 1) * b}; j > i * b; j--)
			ans.push_back(j);
	if (lds < a)
		for (int i{lds * b + rest + 1}; i > lds * b; i--)
			ans.push_back(i);
	for (int i{lds * b + rest + 2}; i <= n; i++)
		ans.push_back(i);
	for (int i{}; i < n; i++)
		printf("%d%c", ans[i], i == n - 1?'\n':' ');

	return 0;
}