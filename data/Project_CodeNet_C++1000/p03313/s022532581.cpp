#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
int main(){
	int n; std::cin >> n;
	std::vector<long long int> numbers(1 << n); for (auto& a : numbers) std::cin >> a;
	std::vector<std::vector<int>> result(1 << n);
	for (auto k = 0; k < (1 << n); ++k) {
		std::vector<int> indices{k};
		for (auto d = 0; d < n; ++d) if ((k & (1 << d)) != 0) {
			for (const auto i : result[(k - (1 << d))]) indices.push_back(i);
		}
		std::sort(indices.begin(), indices.end(), [&numbers](const int a, const int b) {return numbers[a] > numbers[b]; });
		indices.erase(std::unique(indices.begin(), indices.end()), indices.end());
		if (indices.size() > 2) indices.erase(indices.begin() + 2, indices.end());
		result[k] = std::move(indices);
	}
	long long int max = 0;
	for (auto k = 1; k < result.size(); ++k) {
		max = std::max(max, numbers[result[k][0]] + numbers[result[k][1]]);
		//std::cout << "k :" << std::setbase(2) << k << " - ";
		std::cout << max << "\n";
	}
}