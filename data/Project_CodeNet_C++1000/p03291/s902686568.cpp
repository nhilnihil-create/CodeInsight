#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

const int mod = 1e9 + 7;
using VL = vector<long long>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
// dp[i][j] i文字目までみる　ABCのうちj文字採用

int main() {
	string s;
	cin >> s;

	int n = s.size();

	VL memo1(4, 0);
	auto memo2 = memo1;
	memo1[0] = 1;

	for (int i = 0; i < n; i++) {
		auto memo2 = memo1;
		switch (s[i]) {
			case 'A':
				memo2[1] += memo1[0];
				memo2[1] %= mod;
				break;
			case 'B':
				memo2[2] += memo1[1];
				memo2[2] %= mod;
				break;
			case 'C':
				memo2[3] += memo1[2];
				memo2[3] %= mod;
				break;
			case '?':
				memo2[0] *= 3;
				memo2[1] *= 3;
				memo2[2] *= 3;
				memo2[3] *= 3;
				memo2[1] += memo1[0];
				memo2[2] += memo1[1];
				memo2[3] += memo1[2];
				memo2[0] %= mod;
				memo2[1] %= mod;
				memo2[2] %= mod;
				memo2[3] %= mod;
				break;
		}

		// printf("%2d, %c: %3lld, %3lld, %3lld, %3lld\n", i, s[i],
		// memo2[0], memo2[1], memo2[2], memo2[3]);
		memo1 = memo2;
	}

	cout << memo1[3] << endl;
	return 0;
}
