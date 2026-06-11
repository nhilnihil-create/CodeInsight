#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <climits>
#include <numeric>
#include <bitset>
#include <random>
#include <tuple>
#include <initializer_list>
#include <fstream>
#include <cctype>
#include <string>

int main() {
	int m, k; std::cin >> m >> k;
	if (k >= (1 << m) || (k == 1 && m == 1)) {
		std::cout << "-1\n";
	}
	else if (k == 0) {
		for (auto i = 0; i < (1 << m); ++i) {
			if (i != 0) std::cout << ' ';
			std::cout << i << ' ' << i;
		}
		std::cout << std::endl;
	}
	else {
		std::vector<int> result; result.reserve(2 << m);
		std::vector<bool> use(1 << m, false);
		std::queue<int> queue;
		for (auto i = 0; i < (1 << m); ++i) queue.push(i);
		while (!queue.empty()) {
			while (!queue.empty() && use[queue.front()]) {
				queue.pop();
			}
			if (queue.empty()) break;
			const auto first = queue.front();
			use[first] = use[first ^ k] = true;
			while (!queue.empty() && use[queue.front()]) {
				queue.pop();
			}
			const auto second = queue.front();
			use[second] = use[second ^ k] = true;
			result.push_back(first); result.push_back(k ^ first);
			result.push_back(second); result.push_back(k ^ second);
			result.push_back(k ^ first); result.push_back(first);
			result.push_back(k ^ second); result.push_back(second);
		}
		for (auto i = 0; i < result.size(); ++i) {
			if (i != 0) std::cout << ' ';
			std::cout << result[i];
		}
		std::cout << std::endl;
	}
}
