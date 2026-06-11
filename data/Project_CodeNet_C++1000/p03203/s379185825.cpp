#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, N, X[200009], Y[200009]; map<pair<int, int>, int>M;
vector<int>Z[200009];

void add(int px, int py) {
	Z[py].push_back(px);
	M[make_pair(px, py)] = 1;
}

int get_value(int cx, int cy) {
	int pos1 = lower_bound(Z[cy].begin(), Z[cy].end(), cx) - Z[cy].begin();
	if (pos1 == Z[cy].size()) return (1 << 30);
	return Z[cy][pos1];
}

int main() {
	cin >> H >> W >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i];
		add(X[i], Y[i]);
	}
	for (int i = 1; i <= W; i++) add(H + 1, i);
	for (int i = 1; i <= H; i++) add(i, W + 1);
	for (int i = 1; i <= W; i++) sort(Z[i].begin(), Z[i].end());

	int cx = 1, cy = 1, minx = get_value(1, 1);
	while (true) {
		if (M[make_pair(cx + 1, cy)] == 0) {
			cx++;
			if (M[make_pair(cx, cy + 1)] == 0) {
				cy++; minx = min(minx, get_value(cx, cy));
			}
		}
		else {
			break;
		}
	}
	cout << minx - 1 << endl;
	return 0;
}