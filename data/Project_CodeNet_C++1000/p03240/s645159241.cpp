#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
signed main() {
	int n, ng = 0; cin >> n; vector<vector<int>> asd(123456, vector<int>(3));
	for (int h = 0; h < n; h++) {
		cin >> asd[h][2] >> asd[h][1] >> asd[h][0];
	}
	sort(asd.begin(), asd.end()); reverse(asd.begin(), asd.end());
	for (int h = 0; h < n; h++) {
		swap(asd[h][2], asd[h][0]);
	}
	for (int h = 0; h <= 100; h++) {
		for (int i = 0; i <= 100; i++) {
			int z = 0, ok = 0;
			for (int j = 0; j < n; j++) {
				if (asd[j][2] == 0) {
					if (z - abs(asd[j][0] - h) - abs(asd[j][1] - i) > 0) { z = INF; break; }
					continue;
				}
				if (ok == 0) { z = abs(asd[j][0] - h) + abs(asd[j][1] - i) + asd[j][2]; ok++; }
				else {
					if (z != abs(asd[j][0] - h) + abs(asd[j][1] - i) + asd[j][2]) {
						z = INF; break;
					}
				}
			}
			if (z != INF) { cout << h << ' ' << i << ' ' << z << endl; return 0; }
		}
	}
	return 0;
}