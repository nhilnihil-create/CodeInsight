#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <bitset>

#define REP(i, n) for(int i = 0; i < int(n); ++i)

signed main() {

	std::string s;
	int x, y;
	std::cin >> s >> x >> y;
	s += 'T';

	std::vector<int> vx, vy;
	bool flag = true;
	bool first = true;
	int sum = 0;
	REP(i, s.size()) {
		if (s[i] == 'T') {
			if (first) {
				x -= sum;
			}
			else {
				if (sum) (flag ? vx : vy).emplace_back(sum);
			}
			sum = 0;
			flag = !flag;
			first = false;
		}
		else {
			++sum;
		}
	}

	REP(i, vx.size()) {
		x += vx[i];
		vx[i] *= 2;
	}
	REP(i, vy.size()) {
		y += vy[i];
		vy[i] *= 2;
	}

	auto subsetSum = [&](std::vector<int> a, int b) -> bool {
		if (b < 0) return false;
		if (b == 0) return true;
		if (a.empty()) return false;

		std::bitset<20004> bit;
		bit.set(0);

		REP(i, a.size()) {
			bit = bit | (bit << a[i]);
		}

		return bit[b];
	};

	std::cout << (subsetSum(vx, x) && subsetSum(vy, y) ? "Yes" : "No") << std::endl;

	return 0;
}