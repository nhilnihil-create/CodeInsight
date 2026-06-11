#include<iostream>

using namespace std;

int main() {
	int N, X, m[110], sum = 0, min = 10000000, A;

	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> m[i];
		sum += m[i];
		if (min > m[i]) {
			min = m[i];
		}
	}
	A = N + (X - sum) / min;
	cout << A << endl;


	return 0;
}