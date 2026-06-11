#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int N, M; std::cin >> N >> M;
	std::vector<std::vector<int>> s(M);
	for (auto i{ 0 }; i < M; ++i) {
		int k; std::cin >> k;
		for (auto j{ 0 }; j < k; ++j) {
			//予め各電球に対して対応するスイッチの組み合わせを2進数変数に変換しておく。
			int a; std::cin >> a; --a;
			s[i].push_back(a);
		}
	}
	std::vector<int> P(M);
	for (auto& r : P) std::cin >> r;
	
	int ans{ 0 };
	for (int bit{ 0 }; bit < (1 << N); ++bit) {
		bool ok = true;
		for (int i{ 0 }; i < M; ++i) {
			int con{ 0 };
			for (auto& r : s[i])
				//onになっているスイッチの組み合わせと1.で用意した電球に対応するスイッチの組み合わせとでAND演算した結果を取る。
				if (bit & (1 << r))++con;
			if ((con % 2) != P[i])
				ok = false;
		}
		if (ok == true) ++ans;
	}
	std::cout << ans << std::endl;

	return 0;
}