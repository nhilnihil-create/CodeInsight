#include <bits/stdc++.h>

int n;
long long a[100005];
int main()
{
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	std::sort(a, a + n);

	auto end = a[n - 1];
	auto right = std::distance(a, std::lower_bound(a, a + n, end / 2));
	if (right == n - 1)
		--right;
	long long left = 0;
	if (right != 0)
		left = right - 1;

	std::cout << end << " " << (a[left] > end - a[right] ? a[left] : a[right]) << std::endl;
	return 0;
}
