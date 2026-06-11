#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int N, T, A; std::cin >> N >> T >> A;
	std::vector<double> H(N);
	for (auto& r : H) {
		int t{ 0 }; std::cin >> t;
		r = std::abs(A - (T - (t * 0.006)));
	}
	int ans = std::min_element(H.begin(), H.end()) - H.begin() + 1;
	std::cout << ans << std::endl;
	return 0;
}