#include <iostream>
#include <string>
#include <vector>

template <typename H>
H max(const H &head) {
	return head;
}
template <typename H, typename ...Tail>
H max(const H &head, const Tail&... tail) {
	auto tail_max = max(tail...);
	return head > tail_max ? head : tail_max;
}

int max_lcs(const std::string &str, int l, int r, int k, std::vector<std::vector<std::vector<int>>> &memo) {
	if (l > r) return 0;
	if (l == r) return 1;
	if (memo[l][r][k] > 0) return memo[l][r][k];
	int res{ 0 };
	if (str[l] == str[r]) {
		res = max_lcs(str, l + 1, r - 1, k, memo) + 2;
	}
	else if (k != 0) {
		res = max_lcs(str, l + 1, r - 1, k - 1, memo) + 2;
	}
	res = max(res, max_lcs(str, l + 1, r, k, memo), max_lcs(str, l, r - 1, k, memo));
	return memo[l][r][k] = res;
}
int max_lcs(const std::string &str, int k) {
	std::vector<std::vector<std::vector<int>>> memo(str.size() + 1, std::vector<std::vector<int>>(str.size() + 1, std::vector<int>(k + 1, -1)));
	return max_lcs(str, 0, str.size() - 1, k, memo);
}

int main() {
	std::string str;
	int k;
	std::cin >> str >> k;
	std::cout << max_lcs(str, k) << std::endl;
}