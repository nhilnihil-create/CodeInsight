#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int H, W, N, sx, sy;
string S, T;
char U[5] = "URDL";

int main() {
	cin >> H >> W >> N >> sx >> sy;
	cin >> S >> T;

	int lx = 1, ly = 1, rx = H, ry = W;

	for (int i = N - 1; i >= 0; i--) {
		// T についての操作
		if (T[i] == 'L') ry++;
		if (T[i] == 'R') ly--;
		if (T[i] == 'U') rx++;
		if (T[i] == 'D') lx--;
		lx = max(lx, 1); ly = max(ly, 1);
		rx = min(rx, H); ry = min(ry, W);

		// S についての操作
		if (S[i] == 'R') ry--;
		if (S[i] == 'L') ly++;
		if (S[i] == 'D') rx--;
		if (S[i] == 'U') lx++;

		if (lx > rx || ly > ry) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (lx <= sx && sx <= rx && ly <= sy && sy <= ry) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}