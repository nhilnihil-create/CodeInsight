#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> vx(n, 0), vy(n, 0), vh(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> vx[i] >> vy[i] >> vh[i];
	}
	for (int x = 0; x <= 100; x++) {
		for (int y = 0; y <= 100; y++) {
			int h1 = 1, h2 = 1e9 + 200;
			while (h1 <= h2) {
				int m = h1 / 2 + h2 / 2 + (h1 % 2 + h2 % 2) / 2;
				int flag = 0;
				for (int i = 0; i < n; i++) {
					int h = max(0, m - abs(vx[i] - x) - abs(vy[i] - y));
					if (h < vh[i]) {
						flag = 1;
					} else if (h > vh[i]) {
						flag = -1;
					}
				}
				if (flag == 0) {
					cout << x << " " << y << " " << m << endl;
					return 0;
				} else if (flag == 1) {
					h1 = m + 1;
				} else {
					h2 = m - 1;
				}
			}	
		}
	}
}
