#include<iostream>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int Q = N % K;

	if (Q == 0) {
		cout << 0 << endl;
	}
	else cout << 1 << endl;

	return 0;
}