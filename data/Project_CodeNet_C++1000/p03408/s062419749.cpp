#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, m;
	std::cin >> n;
	vector<string> vstr_plus(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vstr_plus[i];
	}

	std::cin >> m;
	vector<string> vstr_minus(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> vstr_minus[i];
	}

	int max_score = 0;

	for (string word : vstr_plus) {
		int score = 0;
		for (string plus : vstr_plus) {
			if (word == plus) {
				++score;
			}
		}
		for (string minus : vstr_minus) {
			if (word == minus) {
				--score;
			}
		}
		if (max_score < score) {
			max_score = score;
		}
	}

	std::cout << max_score << std::endl;

	return 0;
}
