#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <climits>
#include <numeric>
#include <queue>
#include <cmath>
#include <iomanip>
#include <array>
#include <string>
#include <stack>
#include <cassert>
#include <memory>

int main() {
	int n, k; std::cin >> n >> k;
	long long int zero{ n / k};
	long long int half{ ((k & 1) == 0 && (n >= k / 2)) ? (n - k / 2) / k + 1 : 0 };
	std::cout << zero * zero * zero + half * half * half << '\n';
}