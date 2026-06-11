#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int mn = 1010101010;
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			mn = min(mn, abs(a[i]));
		}
	} else {
		for (int i = 0; i + k - 1 < n; i++) {
			int t = 0;
			if (a[i] < 0) {
				if (a[i + k - 1] < 0) {
					t = -a[i];
				} else {
					t = min(-a[i] * 2 + a[i + k - 1], -a[i] + a[i + k - 1] * 2);
				}
			} else {
				t = a[i + k - 1];
			}
			mn = min(mn, t);
		}
	}
	cout << mn << endl;

	return 0;
}