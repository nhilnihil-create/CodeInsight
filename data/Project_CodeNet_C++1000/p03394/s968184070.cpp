#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int main() {
	int N;
	cin >> N;
	if (N < 5) {
		if (N == 3) {
			cout << "2 5 63" << endl;
		}
		if (N == 4) {
			cout << "2 5 20 63" << endl;
		}
		return 0;
	}
	int m = N % 8;
	N /= 8;
	for (int i = 0;i < N;i++) {
		cout << i * 12 + 2 << " "
			<< i * 12 + 3 << " "
			<< i * 12 + 4 << " "
			<< i * 12 + 6 << " "
			<< i * 12 + 8 << " "
			<< i * 12 + 9 << " "
			<< i * 12 + 10 << " "
			<< i * 12 + 12;
		if (i != N - 1 || m != 0) {
			cout << " ";
		}
	}
	if (m == 1) {
		cout << N * 12 + 6 << endl;
	}
	if (m == 2) {
		cout << N * 12 + 4 << " "
			<< N * 12 + 8 << endl;
	}
	if (m == 3) {
		cout << N * 12 + 4 << " "
			<< N * 12 + 6 << " "
			<< N * 12 + 8 << endl;
	}
	if (m == 4) {
		cout << N * 12 + 4 << " "
			<< N * 12 + 6 << " "
			<< N * 12 + 8 << " "
			<< N * 12 + 12 << endl;
	}
	if (m == 5) {
		cout << N * 12 + 2 << " "
			<< N * 12 + 3 << " "
			<< N * 12 + 9 << " "
			<< N * 12 + 10 << " "
			<< N * 12 + 12 << endl;
	}
	if (m == 6) {
		cout << N * 12 + 2 << " "
			<< N * 12 + 3 << " "
			<< N * 12 + 6 << " "
			<< N * 12 + 9 << " "
			<< N * 12 + 10 << " "
			<< N * 12 + 12 << endl;
	}
	if (m == 7) {
		cout << N * 12 + 2 << " "
			<< N * 12 + 3 << " "
			<< N * 12 + 4 << " "
			<< N * 12 + 8 << " "
			<< N * 12 + 9 << " "
			<< N * 12 + 10 << " "
			<< N * 12 + 12 << endl;
	}
	if (m == 0)
		cout << endl;
}