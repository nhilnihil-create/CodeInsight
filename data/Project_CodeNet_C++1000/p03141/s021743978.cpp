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
	std::vector<Int> sum(N); //A + B
	Int ans = 0;
	rep(i, N) {
		Int A, B; std::cin >> A >> B;
		sum[i] = A + B;
		ans -= B;
	}
	std::sort(sum.rbegin(), sum.rend());
	rep(i, N) {
		if (i % 2 == 0)ans += sum[i];
	}

	std::cout << ans;

}


int main() {

	calc();

	return 0;
}