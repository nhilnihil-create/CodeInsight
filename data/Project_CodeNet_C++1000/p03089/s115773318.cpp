#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;

		if (a[i] > i) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<int> ans(n);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			if (a[j] == j) {
				ans[i] = j + 1;
				for (int k = j; k < i; k++) {
					a[k] = a[k + 1];
				}
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}

	return 0;
}