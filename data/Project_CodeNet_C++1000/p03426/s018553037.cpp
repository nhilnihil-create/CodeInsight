#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getDist(int toX, int toY, int fromX, int fromY) {
	return abs(toX - fromX) + abs(toY - fromY);
}

int main() {

	int h, w, d; cin >> h >> w >> d;
	int u = h * w;
	vector<pair<int, int>> coordinate(u + 1);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			int a; cin >> a;
			coordinate[a] = { i,j };
		}
	}
	vector<int> accum(u + 1, 0);
	for (int i = 1; i <= u; i++) {
		if (i <= d) {

		}
		else {
			int toX = coordinate[i].first;
			int toY = coordinate[i].second;
			int fromX = coordinate[i - d].first;
			int fromY = coordinate[i - d].second;;
			accum[i] += getDist(toX, toY, fromX, fromY);
			accum[i] += accum[i - d];
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		cout << accum[r] - accum[l] << endl;
	}
	return 0;
}