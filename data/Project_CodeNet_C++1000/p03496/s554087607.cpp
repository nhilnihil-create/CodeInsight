#include <bits/stdc++.h>
using namespace std;
const int Nmax = 60;

int N;
int a[Nmax];

int main() {
	cin >> N;
	int buf = 0, memo = 0;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		if (abs(buf) <= abs(a[i])) {
			memo = i;
			buf = a[i];
		}
	}

	if (buf == 0) {
		cout << 0 << endl;
		return 0;
	}

	cout << 2 * N - 1 << endl;
	for (int i = 1; i <= N; i++) {
		cout << memo << " " << i << endl;
	}
	if (buf > 0) {
		for (int i = 1; i <= N - 1; i++) {
			cout << i << " " << i + 1 << endl;
		}
	}
	else {
		for (int i = N; i >= 2; i--) {
			cout << i << " " << i - 1 << endl;
		}
	}
}
