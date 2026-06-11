#include<iostream>

using namespace std;

int main() {


	int n, m;

	int b[25];
	int a[25];
	int c;
	int ans = 0;
	cin >> n >> m >> c;

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < n; i++) {
		int calc = 0;
		for (int i = 0; i < m; i++) {
			cin >> a[i];
			calc += a[i] * b[i];
		}
		calc += c;

		if (calc > 0) {
			ans++;
		}
	}

	cout << ans << endl;
}