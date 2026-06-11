#include <bits/stdc++.h>

using namespace std;

const int N = 55;
string s[N];
int h, w;

bool val(int x, int y) {
	return 0 <= x && x < h && 0 <= y && y < w;
}

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (s[i][j] == '.') continue;
			bool is = false;
			is |= val(i - 1, j) && s[i-1][j] == '#';
			is |= val(i + 1, j) && s[i+1][j] == '#';
			is |= val(i, j - 1) && s[i][j-1] == '#';
			is |= val(i, j + 1) && s[i][j+1] == '#';
			if (!is) {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
    return 0;
}
