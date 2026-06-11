#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	intt R, G, B, N; std::cin >> R >> G >> B >> N;
	intt ans = 0;
	for (intt i = 0; i < N / R + 1; ++i) {
		for (intt j = 0; j < N / G + 1; ++j) {
			if (i * R + j * G > N)
				continue;
			intt d = N - i * R - j * G;
			if (d % B != 0)
				continue;
			++ans;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}