/*
このコード、と～おれ!
Be accepted!
∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
 　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
			　　　　　　　　　　(¸.·´ (¸.·'* ☆
					*/

#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <climits>
#include <tuple>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <memory>
#include <iomanip>

#define rep(i, n) for(Int (i) = 0; (i) < (n); ++(i))
#define debug(var) std::cout << #var << ": " << var << "\n"
using Int = int64_t;
constexpr Int INF = INT_MAX;
constexpr Int mod = 1e9 + 7;

///nの約数を列挙する関数。計算量はO(√n)
std::vector<Int> Divisor(Int n) {
	std::vector<Int> res;
	for (Int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n)res.push_back(n / i);
		}
	}
	std::sort(std::begin(res), std::end(res));
	return res;
}

void calc() {

	Int N, M; std::cin >> N >> M;
	auto divisor = Divisor(M);
	Int ans = 0;
	for (const auto& elem : divisor) {
		if (M >= elem * N)ans = elem;
	}

	std::cout << ans;

}


int main() {

	calc();

	return 0;
}