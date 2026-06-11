#include <iostream>
#include <cmath>

#define NMAX 100001

using namespace std;

int main()
{
	int a[NMAX];
	a[0] = 0;
	a[1] = 0;
	for (int i = 2; i < NMAX; i++) {
		a[i] = 1;
	}
	for (int i = 2; i <= sqrt(NMAX); i++) {
		if (a[i] == 1) {
			for (int j = i + i; j < NMAX; j += i) {
				a[j] = 0;
			}
		}
	}

	int b[NMAX] = {};
	for (int i = 1; i < NMAX; i += 2) {
		if (a[i] == 1 && a[(i + 1) / 2] == 1) {
			b[i] = 1;
		}
	}
	for (int i = 1; i < NMAX; i += 2) {
		if (a[i] == 1 && a[(i + 1) / 2] == 1) {
			b[i] = 1;
		}
	}
	for (int i = 1; i < NMAX; i++) {
		b[i] += b[i - 1];
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--;
		cout << b[r] - b[l] << endl;
	}

	return 0;
}