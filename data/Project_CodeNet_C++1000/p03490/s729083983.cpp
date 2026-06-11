#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
constexpr ll inf = static_cast<ll>(1e17);
constexpr ll mod = static_cast<ll>(1e9 + 7);

std::string s;
int x, y;
bool dpX[16005][16005];
bool dpY[16005][16005];
int main() {
	std::cin >> s;
	std::cin >> x >> y;

	s += 'T';

	std::vector<int> xy[2];
	int sum = 0;
	int turn = 0;
	for (int i = 0, end = s.size(); i < end; ++i) {
		if (s[i] == 'T') {
			xy[turn].emplace_back(sum);
			turn = (turn + 1) % 2;
			sum = 0;
		}
		else {
			++sum;
		}
	}

	dpX[1][xy[0][0] + 8000] = true;
	for (int i = 1, end = xy[0].size(); i < end; ++i)
		for (int j = 0; j <= 16000; ++j) {
			auto val = xy[0][i];
			bool b1 = j - val >= 0 && dpX[i][j - val];
			bool b2 = j + val <= 16000 && dpX[i][j + val];
			dpX[i + 1][j] = b1 || b2;
		}

	dpY[0][8000] = true;
	for (int i = 0, end = xy[1].size(); i < end; ++i)
		for (int j = 0; j <= 16000; ++j) {
			auto val = xy[1][i];
			bool b1 = j - val >= 0 && dpY[i][j - val];
			bool b2 = j + val <= 16000 && dpY[i][j + val];
			dpY[i + 1][j] = b1 || b2;
		}

	if (dpX[xy[0].size()][x + 8000] && dpY[xy[1].size()][y + 8000])
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	return 0;
}
