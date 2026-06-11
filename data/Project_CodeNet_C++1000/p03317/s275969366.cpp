#include "bits/stdc++.h"

typedef long long ll;

int main()
{
	int n, k;
	std::cin >> n >> k;
	int ndx = 0;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		if (a[i] < ndx)
		{
			ndx = i;
		}
	}
	int ans = 1;
	n -= k;
	while (n > 0)
	{
		n -= k - 1;
		++ans;
	}
	std::cout << ans << '\n';
	return 0;
}