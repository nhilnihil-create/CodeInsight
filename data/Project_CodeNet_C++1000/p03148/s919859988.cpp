#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>


int main() {
	int n, k; std::cin >> n >> k;
	std::vector<std::pair<int, int>> sushi(n);
	for (auto& pair : sushi) {
		std::cin >> pair.first >> pair.second;
		pair.first--;
	}
	std::sort(sushi.begin(), sushi.end(), [](const std::pair<int, int> a, const std::pair<int, int> b) {return a.second > b.second; });
	std::vector<int> min_score(n);
	std::vector<bool> appear(n, false);
	std::priority_queue<int, std::vector<int>, std::greater<>> used;
	std::priority_queue<int> not_use;
	long long int sum = 0, type = 0;
	for (int i = 0; i < k; ++i) {
		if (!appear[sushi[i].first]) {
			appear[sushi[i].first] = true;
			++type;
		}
		else {
			used.push(sushi[i].second);
		}
		sum += sushi[i].second;
	}
	for (auto i = k; i < n; ++i) {
		if (!appear[sushi[i].first]) {
			appear[sushi[i].first] = true;
			not_use.push(sushi[i].second);
		}
	}
	long long int max = sum + type * type;
	while (!used.empty() && !not_use.empty()) {
		sum += not_use.top() - used.top();
		not_use.pop(); used.pop(); ++type;
		max = std::max(max, sum + type * type);
	}
	std::cout << max << std::endl;
}
