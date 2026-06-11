#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N);

	for (int &a : A) {
		cin >> a;
	}
	
	int a_max, a_min,idx_max,idx_min;

	idx_max = idx_min = 0;
	a_max = a_min = A[0];
	for (int i = 1; i < N; i++) {
		if (a_max < A[i]) {
			idx_max = i;
			a_max = A[i];
		}
		if (a_min > A[i]) {
			idx_min = i;
			a_min = A[i];
		}
	}

	if (a_max == a_min) {
		cout << 0 << endl;
	}
	else {
		cout << 2*N - 2 << endl;
		if (abs(a_max) >= abs(a_min)) {
			for (int i = 0; i < N; i++)
			{
				if (i != idx_max) {
					cout << idx_max + 1 << " " << i+ 1 << endl;
				}
			}
			for (int i = 1; i < N; i++) {
				cout << i << " " << i + 1 << endl;
			}
		}
		else {
			for (int i = 0; i < N; i++)
			{
				if (i != idx_min) {
					cout << idx_min + 1 << " " << i + 1 << endl;
				}
			}
			for (int i = N; i > 1; i--) {
				cout << i << " " << i - 1 << endl;
			}
		}
	}


	return 0;
}