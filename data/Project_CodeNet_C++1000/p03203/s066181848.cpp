#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W, N;
	cin >> H >> W >> N;
	vector<pair<int, int>> points;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		points.push_back(pair<int, int>(x, y));
	}

	sort(points.begin(), points.end());

	int z = H;
	int c = 0;
	for (int i = 0; i < N; i++) {
		pair<int, int> p = points[i];
		int x = p.first, y = p.second;
		if (y > x-c) continue;
		else if (y == x - c) {
			c++;
		}
		else {
			z = x - 1;
			break;
		}
	}
	cout << z << endl;
	return 0;
}