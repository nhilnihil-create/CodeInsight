#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
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
#include <set>

long long int count_tuple(long long int count) {
	return count * (count - 1) * (count - 2) +
		count * (count - 1) * 3 +
		count;
}
int main() {
	int n, k; std::cin >> n >> k;
	if (k % 2 == 0) {
		std::cout << count_tuple(n / k) + count_tuple((n + k / 2) / k) << std::endl;
	}
	else {
		std::cout << count_tuple(n / k) << std::endl;
	}
}
