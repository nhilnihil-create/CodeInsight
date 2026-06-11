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
int lower_bound(int from, int until, const std::vector<long long int>& vec, const long long int target) {
	while (from < until) {
		auto mid = (from + until) / 2;
		if (vec[mid] < target) from = mid + 1;
		else until = mid;
	}
	return until;
}
int main(){
	int n; std::cin >> n;
	std::vector<long long int> numbers(n + 1, 0);
	for (auto i = 1; i <= n; ++i) {
		int a; std::cin >> a;
		numbers[i] = numbers[i - 1] + a;
	}
	long long int min_diff = LLONG_MAX;
	for (auto mid = 2; mid < numbers.size() - 2; ++mid) {
		auto left = lower_bound(1, mid, numbers, numbers[mid] / 2);
		auto min_left = std::max(std::min(numbers[left], numbers[mid] - numbers[left]), std::min(numbers[left - 1], numbers[mid] - numbers[left - 1]));
		auto max_left = std::min(std::max(numbers[left], numbers[mid] - numbers[left]), std::max(numbers[left - 1], numbers[mid] - numbers[left - 1]));
		auto right = lower_bound(mid, numbers.size(), numbers, (numbers.back() - numbers[mid]) / 2 + numbers[mid]);
		auto min_right = std::max(std::min(numbers.back() - numbers[right], numbers[right] - numbers[mid]), std::min(numbers.back() - numbers[right - 1], numbers[right - 1] - numbers[mid]));
		auto max_right = std::min(std::max(numbers.back() - numbers[right], numbers[right] - numbers[mid]), std::max(numbers.back() - numbers[right - 1], numbers[right - 1] - numbers[mid]));
		auto diff = std::max(max_left, max_right) - std::min(min_left, min_right);
		if (min_diff > diff) min_diff = diff;
	}
	std::cout << min_diff << std::endl;
}

