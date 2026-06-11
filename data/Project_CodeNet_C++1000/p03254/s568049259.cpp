#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int main() {
	int N, x, A[MAX];
	long long sum = 0;
	cin >> N >> x;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	if (sum == x) {
		cout << N << endl;
	} else if (x > sum) {
		cout << N - 1 << endl;
	} else {
		sort(A, A + N);
		for (int i = 0; i < N; i++) {
			if (x >= A[i]) {
				x -= A[i];
			} else {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}
