#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, ans = 0;
	char C[300][300];
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> C[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		char D[300][300];
		bool check = true;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				D[j][k] = C[(j + i) % N][k];
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (D[j][k] != D[k][j]) check = false;
			}
		}
		if (check) ans += N;
	}
	cout << ans;
}