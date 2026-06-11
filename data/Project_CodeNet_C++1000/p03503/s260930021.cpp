#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> f(n, vector<int>(10)), p(n, vector<int>(11));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> f[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> p[i][j];
		}
	}

	long long mx = -101010101010101010;
	for (int i = 1; i < (1 << 10); i++) {
		int a[10];
		for (int j = 0; j < 10; j++) {
			if (((i >> j) % 1) == 1) {
				a[j] = 1;
			} else {
				a[j] = 0;
			}
		}

		long long t = 0;
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int k = 0; k < 10; k++) {
				if (f[j][k] == 1 && ((i >> k) & 1) == 1) {
					cnt++;
				}
			}
			t += p[j][cnt];
		}
		mx = max(mx, t);
	}
	cout << mx << endl;

	return 0;
}