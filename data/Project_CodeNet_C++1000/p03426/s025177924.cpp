#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cost(int i, int j, int x, int y) {
	return abs(x - i) + abs(y - j);
}

int main() {
	
	int h, w, d; cin >> h >> w >> d;
	vector<pair<int, int>> pa(h * w);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int a; cin >> a;
			a--;
			pa[a].first = i;
			pa[a].second = j;
		}
	}
	vector<int> accum(h * w + 1, 0);
	for (int i = d + 1; i <= h * w; i++) {
		accum[i] += accum[i - d];
		accum[i] += cost(pa[i - 1].first, pa[i - 1].second, pa[i - 1 - d].first, pa[i - 1 - d].second);
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		cout << accum[r] - accum[l] << endl;
	}
	return 0;
}