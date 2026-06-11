#include <iostream>
#include <vector>
#include <numeric>

int main()
{
	int n, m, c;
	std::cin >> n >> m >> c;
	std::vector<int> b(m);
	for (auto &e : b) std::cin >> e;
	
	std::vector<int> a(m);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> a[j];
			a[j] *= b[j];
		}
		if (std::accumulate(a.begin(), a.end(), c) > 0) {
			cnt++;
		}
	}
	
	std::cout << cnt << std::endl;
	
	return 0;
}
