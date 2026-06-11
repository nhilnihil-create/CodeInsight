#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
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

int main() {
	int n; std::cin >> n;
	std::string str; std::cin >> str;
	auto reversed = str; std::reverse(reversed.begin(), reversed.end());
	auto hash = [](const std::pair<std::string, std::string>& pair) {return std::hash<std::string>()(pair.first) ^ std::hash<std::string>()(pair.second); };
	std::unordered_map<std::pair<std::string, std::string>, int, decltype(hash)> map(1 << n, hash);
	for (auto i = 0; i < (1 << n); ++i) {
		std::string blue, red;
		for (auto j = 0; j < n; ++j) {
			if ((i & (1 << j)) != 0) blue.push_back(str[j]);
			else red.push_back(str[j]);
		}
		map[std::make_pair(blue, red)]++;
	}
	long long int result = 0;
	for (auto i = 0; i < (1 << n); ++i) {
		std::string blue, red;
		for (auto j = 0; j < n; ++j) {
			if ((i & (1 << j)) != 0) blue.push_back(reversed[j]);
			else red.push_back(reversed[j]);
		}
		result += map[std::make_pair(blue, red)];
	}
	std::cout << result << std::endl;
}