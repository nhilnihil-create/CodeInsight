#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a[55], n, maxi = 0, cur = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (abs(a[i]) > maxi) {
			maxi = abs(a[i]);
			cur = i;
		}
	}
	cout << n * 2 - 1 << endl;
	for (int i = 0; i < n; i++)cout << cur + 1 << ' ' << i + 1 << endl;
	if (a[cur] >= 0)for (int i = 0; i < n - 1; i++)cout << i + 1 << ' ' << i + 2 << endl;
	else for (int i = n - 1; i > 0; i--)cout << i + 1 << ' ' << i << endl;

	return 0;
}