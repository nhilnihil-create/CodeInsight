#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int n, y;
	cin >> n >> y;
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 4000; j++) {
			int rest = y - 10000 * i - 5000 * j;
			if (rest >= 0 && rest % 1000 == 0 && i + j + rest / 1000 == n) {
				cout << i << " " << j << " " << rest / 1000 << endl;
				return 0;
			}
		}
	}
	cout << -1 << " " << -1 << " " << -1 << endl;
}