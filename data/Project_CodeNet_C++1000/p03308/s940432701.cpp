#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N, A[110] = {},sabun, max=0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sabun = abs(A[i] - A[j]);
			if (max < sabun) {
				max = sabun;
			}
		}
	}

	cout << max << endl;

	return 0;
}