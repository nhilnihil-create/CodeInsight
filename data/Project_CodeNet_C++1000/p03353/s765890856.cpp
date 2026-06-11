#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	std::string s;
	int k;

	std::cin >> s >> k;

	int n = int(s.length());
	std::vector<std::string> dat;

	for (int len = 1; len <= k; len++) {
		for (int i = 0; i + len <= n; i++) {
			dat.push_back(s.substr(i, len));
		}
	}

	std::sort(dat.begin(), dat.end());

	dat.erase(unique(dat.begin(), dat.end()), dat.end());

	std::cout << dat[k - 1] << '\n';

	return 0;
}