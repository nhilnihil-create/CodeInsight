#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, A[50], MAX = 0, MIN = 0;
	cin >> N >> A[0];
	for (int i = 1; i < N; i++) {
		cin >> A[i];
		if (A[MAX] < A[i]) MAX = i;
		if (A[MIN] > A[i]) MIN = i;
	}
	cout << (N - 1) * 2 << endl;
	if (abs(A[MAX]) > abs(A[MIN])) {
		for (int i = 0; i < N; i++) {
			if (i == MAX) continue;
			cout << MAX + 1 << " " << i + 1 << endl;
		}
		for (int i = 1; i < N; i++) {
			cout << i << " " << i + 1 << endl;
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			if (i == MIN) continue;
			cout << MIN + 1 << " " << i + 1 << endl;
		}
		for (int i = N; i > 1; i--) {
			cout << i << " " << i - 1 << endl;
		}
	}
}