#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<long long int> A(6);
	for (int i = 0; i < 6; i++) {
		cin >> A[i];
	}
	long long int Min = A[1];
	int rec = 0;
	for (int i = 1; i < 6; i++) {
		if (Min >= A[i]) {
			Min = A[i];
			rec = i;
		}
	}
	if (A[0] % A[rec] != 0) {
		cout << (A[0] / A[rec]) + 5 << endl;
	}
	else {
		cout << (A[0] / A[rec]) + 4 << endl;
	}
	return 0;
}