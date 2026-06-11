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


void calc() {

	Int N; std::cin >> N;
	std::vector<Int> A(N);
	rep(i, N)std::cin >> A[i];
	std::vector<Int> S(N + 1);
	S[0] = 0;
	for (Int i = 1; i <= N; ++i) {
		S[i] = S[i - 1] + A[i - 1];
	}
	std::unordered_map<Int, Int> m;
	rep(i, N + 1)m[S[i]]++;
	Int ans = 0;
	for (const auto& elem : m) {
		if (elem.second >= 2)
			ans += (elem.second * (elem.second - 1) / 2);
	}
	std::cout << ans;

}


int main() {

	calc();

	return 0;
}