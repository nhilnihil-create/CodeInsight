#include<iostream>
#include<array>
using namespace std;
int main() {
	int n;
	int b[101], c[101];
	cin >> n;
	int i,j,k;
	for (i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int maxa, maxb;

	for (i = n; i >= 1; i--) {
		for (j = i; j >= 1; j--) {
			if (b[j] > j) {
				cout << -1;
				return 0;
			}
			else if (b[j] == j) {
				c[i] = j;
				for (k = j; k < n; k++) {
					b[k] = b[k + 1];
				}
				break;
			}
		}
		/*maxa = 0;
		maxb = -1;
		for (j = 0; j < i; j++) {
			if (b[i] > maxa) {
				maxa = b[i];
				maxb = i;
			}
		}
		if (maxa > i) {
			cout << -1;
			return 0;
		}
		else {
			c[i - 1] = maxa;
			for (j = maxb; j < i - 1; j++) {
				b[j] = b[j + 1];
			}
		}*/
	}
	for (i = 1; i <= n; i++) {
		cout << c[i];
		cout << '\n';
	}
	return 0;
}