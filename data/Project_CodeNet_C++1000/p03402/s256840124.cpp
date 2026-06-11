#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int h = 20;
	int w = 99;

	vector<string> white(h, string(w, '#'));
	vector<string> black(h, string(w, '.'));

	a--;
	b--;
	for (int i = 0; i < h; i += 2) {
		for (int j = 0; j < w; j += 2) {
			if (a > 0) {
				white[i][j] = '.';
				a--;
			}
		}
	}

	for (int i = 1; i < h; i += 2) {
		for (int j = 0; j < w; j += 2) {
			if (b > 0) {
				black[i][j] = '#';
				b--;
			}
		}
	}

	cout << 2 * h << " " << w << endl;
	for (auto s: white) {
		cout << s << endl;
	}
	for (auto s: black) {
		cout << s << endl;
	}
	return 0;
}
