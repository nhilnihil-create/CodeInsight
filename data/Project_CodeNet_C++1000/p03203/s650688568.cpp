#include <iostream>
#include <string>

#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <algorithm>


int main()
{
	int H, W;
	int N;
	std::map<int, int> pos;
	std::vector<int> ypos;

	std::cin >> H >> W >> N;
	ypos.resize(H);
	for (int i = 0; i < H; ++i)
		ypos[i] = -1;
	for (int i = 0; i < N; ++i) {
		int x, y;
		std::cin >> x >> y;
		--x;
		--y;
		if (y > x)
			continue;
		int z = x - y;
		if (ypos[z] == -1)
			ypos[z] = x;
		else if (ypos[z] > x)
			ypos[z] = x;
	}
	for (int i = 0; i < H; ++i) {
		if (ypos[i] != -1)
			pos[ypos[i]] = i;
	}

	int aoki_pass = 0;
	for (auto it = pos.begin(); it != pos.end(); ++it) {
		if (it->second == aoki_pass) {
			++aoki_pass;
			continue;
		} else {
			std::cout << it->first << "\n";
			return 0;
		}
	}
	std::cout << H << "\n";
}
