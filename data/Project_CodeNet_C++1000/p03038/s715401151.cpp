#include <iostream>
#include <algorithm>

bool compare(const int& lhs, const int& rhs) {
	return lhs > rhs;
}

bool comparepair(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
	return lhs.second > rhs.second;
}


int main() {
	
	int n, m;
	std::cin >> n >> m;

	int a[100010];

	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::pair<int, int> pairs[100010];
	for (int i = 0; i < m; ++i) {
		std::cin >> pairs[i].first >> pairs[i].second;
	}

	std::sort(a, a + n, compare);
	std::sort(pairs, pairs + m, comparepair);

	long long int sum = 0;
	int it1 = 0, it2 = 0;
	for (int i = 0; i < n; ++i) {

		if (it2 > m) {
			sum += a[it1];
			++it1;
		}
		else
		{
			if (a[it1] >= pairs[it2].second) {
				sum += a[it1];
				++it1;
			}
			else
			{
				sum += pairs[it2].second;
				--pairs[it2].first;
				if (pairs[it2].first == 0)
					++it2;
			}
		}
	}

	std::cout << sum;
}