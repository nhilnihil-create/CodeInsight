#include<iostream>
using namespace std;

int main() {
	int N; cin >> N;
	if (N % 2) {
		cout << N * (N - 1) / 2 - N / 2 << endl;
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (i + j != N) {
					cout << i << ' ' << j << endl;
				}
			}
		}
	}
	else {
		cout << N * (N - 1) / 2 - N / 2 << endl;
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (i + j != N + 1) {
					cout << i << ' ' << j << endl;
				}
			}
		}
	}

	return 0;
}