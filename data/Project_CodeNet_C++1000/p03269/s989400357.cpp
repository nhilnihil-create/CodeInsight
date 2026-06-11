#include<iostream>

using namespace std;

int L;

int bitct(int a) {
	int rtn = 0;
	while (a > 0) {
		if (a & 1)rtn++;
		a >>= 1;
	}
	return rtn;
}

int main() {
	cin >> L;
	int N = 0, M = 0;
	while ((1 << N) <= L)N++;
	N--;
	M = N * 2 + bitct(L) - 1;

	cout << N + 1 << " " << M << endl;

	for (int i = 0; i < N; i++) {
		cout << i + 1 << " " << i + 2 << " " << (1 << i) << endl;
		cout << i + 1 << " " << i + 2 << " " << 0 << endl;
	}

	int ct = (1 << N);

	for (int i = N - 1; i >= 0; i--) {
		if (L & (1 << i)) {
			cout << i + 1 << " " << N + 1 << " " << ct << endl;
			ct += (1 << i);
		}
	}

	return 0;
}