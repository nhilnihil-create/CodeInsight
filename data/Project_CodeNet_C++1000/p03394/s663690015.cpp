#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, Odd[8] = { 6, 2, 10, 3, 9, 4, 8, 12 }, Even[8] = { 2, 10, 3, 9, 4, 8, 6, 12 };
	cin >> N;
	if (N == 3) {
		cout << "2 5 63\n";
		return 0;
	}
	if (N % 2 == 0) {
		for (int i = 0; i < N; i++) {
			if (i != 0) cout << " ";
			cout << Even[i % 8];
			Even[i % 8] += 12;
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (i != 0) cout << " ";
			cout << Odd[i % 8];
			Odd[i % 8] += 12;
		}
	}
	cout << endl;
}