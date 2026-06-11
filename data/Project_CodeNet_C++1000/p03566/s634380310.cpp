#include <iostream>
#include <iomanip>
#include <algorithm>

int n, t[105], v[105];
long double maxv[40005];
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> t[i];
		if (i != 0)
			t[i] += t[i - 1];
	}

	for (int i = 0; i < n; ++i)
		std::cin >> v[i];

	{
		long long tmp = 1;
		for (long long i = 0; i < n; i++) {
			while (tmp < 2 * t[i]) {
				maxv[tmp] = v[i];
				tmp++;
			}
			maxv[tmp] = std::min(v[i], v[i + 1]);
			tmp++;
		}
	}

	for (long long i = 0; i < 2 * t[n - 1]; ++i)
		maxv[i + 1] = std::min(maxv[i] + 0.5, maxv[i + 1]);

	for (long long i = 2 * t[n - 1]; i > 0; --i)
		maxv[i - 1] = std::min({ maxv[i - 1], maxv[i] + 0.5 });

	long double ans = 0;
	for (long long i = 0; i < 2 * t[n - 1]; ++i)
		ans += (maxv[i] + maxv[i + 1]) / 4;

	std::setprecision(15);
	std::cout << std::fixed << ans << std::endl;
	return 0;
}
