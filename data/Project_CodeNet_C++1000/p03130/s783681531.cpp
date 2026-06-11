#include <iostream>
#include <algorithm>
using namespace std;

int A[3], B[3], C[4] = { 1, 2, 3, 4 };
bool used[5][5];

int main() {
	for (int i = 0; i < 3; i++) {
		cin >> A[i] >> B[i];
		used[A[i]][B[i]] = true;
		used[B[i]][A[i]] = true;
	}
	do {
		bool flag = true;
		for (int i = 0; i < 3; i++) {
			if (used[C[i]][C[i + 1]] == false) flag = false;
		}
		if (flag == true) {
			cout << "YES" << endl;
			return 0;
		}
	} while (next_permutation(C, C + 4));

	cout << "NO" << endl;
	return 0;
}