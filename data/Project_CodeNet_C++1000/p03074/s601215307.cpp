#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	string s;
	cin >> n >> k >> s;

	vector<int> a;
	if (s[0] == '0') {
		a.emplace_back(0);
	}
	a.emplace_back(1);
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i - 1]) {
			a[a.size() - 1]++;
		} else {
			a.emplace_back(1);
		}
	}
	if (s[n - 1] == '0') {
		a.emplace_back(0);
	}

	if (a.size() / 2 <= k) {
		cout << n << endl;
	} else {
		int mx = 0;
		int sum = 0;
		for (int i = 0; i <= 2 * k; i++) {
			mx += a[i];
		}
		sum = mx;

		for (int i = 0; i < a.size() / 2 - k; i++) {
			sum -= a[i * 2];
			sum -= a[i * 2 + 1];
			sum += a[i * 2 + 2 * k + 1];
			sum += a[i * 2 + 2 * k + 2];

			mx = max(mx, sum);
		}
		cout << mx << endl;
	}

	return 0;
}