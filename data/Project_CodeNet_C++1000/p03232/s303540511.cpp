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
constexpr long long int MOD = 1000000007LL;

long long int power(long long int base, int exp) {
	switch (exp) {
	case 0: return 1LL;
	case 1: return base % MOD;
	default: return power(base * base % MOD, exp / 2) * power(base, exp % 2) % MOD;
	}
}
int main() {
	int n; std::cin >> n;
	std::vector<int> numbers(n); for (auto& a : numbers) std::cin >> a;
	std::vector<long long int> factorial(n + 1, 1LL), inverse(n + 1, 1LL);
	for (auto i = 2; i <= n; ++i) {
		factorial[i] = i * factorial[i - 1] % MOD;
		inverse[i] = (MOD - MOD / i) * inverse[MOD % i] % MOD;
	}
	std::vector<long long int> sum = inverse;
	for (auto i = 2; i < sum.size(); ++i) sum[i] = (sum[i] + sum[i - 1]) % MOD;
	long long int result = 0;
	for (auto i = 0; i < n; ++i) {
		result += (numbers[i] * (sum[i + 1] + sum[n - i] - 1)) % MOD;
		result %= MOD;
	}
	result *= factorial[n];
	std::cout << result % MOD << '\n';
}