#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	long long int A, B, K;
	cin >> A >> B >> K;
	if (B - A + 1 >= 2 * K) {
		for (long long int i = 0; i < K; i++) {
			cout << A + i << endl;
		}
		for (long long int i = 0; i < K; i++) {
			cout << B - K + 1 + i << endl;
		}
	}
	else {
		for (long long int i = A; i <= B; i++) {
			cout << i  << endl;
		}
	}
	return 0;
}