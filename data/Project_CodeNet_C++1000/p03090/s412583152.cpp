#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n%2 == 0) {
		int m = (n-2) * n / 2;
		cout << m << endl;
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j <= n; j++) {
				if (i+j != n+1) cout << i << ' ' << j << endl;
			}
		}
	} else {
		int m = (n-1) * (1 + (n-3)/2);
		cout << m << endl;
		for (int i = 1; i < n; i++) {
			for (int j = i+1; j <= n; j++) {
				if (i+j != n) cout << i << ' ' << j << endl;
			}
		}
	}
	return 0;
}
