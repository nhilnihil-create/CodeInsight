#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;

	for (int i = 0; i * 4 <= n; i++) {
		int sum = i * 4;
		for (int j = 0; j * 7 + sum <= n; j++) {
			sum += j * 7;
			if (sum == n) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;

	return 0;
}