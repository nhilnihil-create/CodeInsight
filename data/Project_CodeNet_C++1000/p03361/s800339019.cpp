#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;



int main() {
	int h, w;
	cin >> h >> w;

	vector<string> s(50);
	for (int i = 0; i < h; i++) {
		cin >> s.at(i);
	}

	vector<int> x{ 1, -1, 0, 0};
	vector<int> y{ 0, 0, 1, -1};
	bool flag1 = true;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			bool flag2 = false;
			if (s.at(i).at(j) == '.') continue;

			for (int k = 0; k < 4; k++) {
				int dx = i + x.at(k);
				int dy = j + y.at(k);

				if (dx >= h || dx < 0) continue;
				if (dy >= w || dy < 0) continue;
				if (s.at(dx).at(dy) == '#') flag2 = true;
			}
			if (!flag2) {
				flag1 = false;
				break;
			}
		}
	}

	if (flag1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}