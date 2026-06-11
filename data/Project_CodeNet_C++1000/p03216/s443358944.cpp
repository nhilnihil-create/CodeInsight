#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <climits>
#include <stack>
#include <string>
#include <random>
enum class Char: char {
	D, M, C
};
struct Char_with_index {
	Char charactor;
	int index;
};
long long int search(const std::vector<Char_with_index> &vec, const int k) {
	int left = 0, current = 0, d = 0, m = 0;
	long long int memo = 0, result = 0;
	while (current < vec.size()) {
		while (vec[left].index + k <= vec[current].index) {
			switch (vec[left].charactor) {
			case Char::D:
				--d;
				memo -= m;
				break;
			case Char::M:
				--m;
				break;
			case Char::C: break;
			}
			++left;
		}

		switch (vec[current].charactor) {
		case Char::D:
			++d;
			break;
		case Char::M:
			++m;
			memo += d;
			break;
		case Char::C:
			result += memo;
			break;
		}
		++current;
	}
	return result;
}
int main() {
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	std::vector<Char_with_index> vec;
	for (auto i = 0; i < str.size(); ++i) {
		switch (str[i]) {
		case 'D': vec.push_back({ Char::D, i }); break;
		case 'M': vec.push_back({ Char::M, i }); break;
		case 'C': vec.push_back({ Char::C, i }); break;
		default: break;
		}
	}
	int q;
	std::cin >> q;
	int k;
	for (auto i = 0; i < q; ++i) {
		std::cin >> k;
		std::cout << search(vec, k) << std::endl;
	}
}
/*
*/