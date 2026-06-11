#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, H, W;
	cin >> N >> H >> W;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		if ((x >= H) && (y >= W)) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}