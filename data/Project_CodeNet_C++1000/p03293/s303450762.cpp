#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	std::string S, T; std::cin >> S >> T;
	int N = S.size();
	for (int i = 0; i < S.size(); ++i) {
		if (S == T) {
			std::cout << "Yes" << std::endl;
			return 0;
		}
		char save = S[N - 1];
		for (int i = S.size() - 2; i >= 0; --i) {
			S[i + 1] = S[i];
		}
		S[0] = save;
	}
	std::cout << "No" << std::endl;

	return 0;
}