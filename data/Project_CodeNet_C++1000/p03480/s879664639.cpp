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
bool can_make(const std::string& str, const int k) {
	int one = 0, zero = 0;
	for (int i = str.size() - k; i < k; ++i) {
		if (str[i] == '1') ++one;
		else ++zero;
	}
	return one == 0 || zero == 0;
}
int main() {
	std::string str; std::cin >> str;
	int min = 1;
	int max = str.size() + 1;
	while (min < max) {
		auto mid = (min + max) / 2;
		if (can_make(str, mid)) min = mid + 1;
		else max = mid;
	}
	std::cout << max - 1 << std::endl;
}
