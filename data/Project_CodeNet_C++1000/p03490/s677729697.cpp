#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
std::string S;
std::vector<int> F[2];
bool went[8010][16010];
int x, y;
int main() {
	std::cin >> S;
	std::cin >> x >> y;
	int ac = 0;
	int r = 0;
	for (auto u : S) {
		if (u == 'T') {
			F[ac].push_back(r);
			r = 0;
			ac = (ac + 1) % 2;
		}
		else {
			r++;
		}
	}
	F[ac].push_back(r);
	went[0][8000] = true;
	for (int i = 0; i<F[0].size(); i++) {
		for (int j = 0; j <= 16000; j++) {
			if (i == 0 && S[0] == 'F') {
				went[i + 1][8000 + F[0][i]] = true;
				break;
			}
			if (went[i][j])went[i + 1][j - F[0][i]] = went[i + 1][j + F[0][i]] = true;
		}
	}
	if (!went[F[0].size()][x + 8000]) {
		std::cout << "No" << std::endl;
		return 0;
	}
	for (int i = 0; i <= 8000; i++) {
		for (int j = 0; j<16010; j++) {
			went[i][j] = false;
		}
	}
	went[0][8000] = true;
	for (int i = 0; i<F[1].size(); i++) {
		for (int j = 0; j <= 16000; j++) {
			if (went[i][j])went[i + 1][j - F[1][i]] = went[i + 1][j + F[1][i]] = true;
		}
	}
	std::cout << (went[F[1].size()][8000+y] ? "Yes" : "No") << std::endl;
	return 0;
}