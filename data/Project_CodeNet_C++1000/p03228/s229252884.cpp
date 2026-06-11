#include <iostream>
using namespace std;

int main() {
	int A, B, K;
	cin >> A >> B >> K;
	for (int i = 0; i < K; i++) {
		if (A % 2 == 1) A--;
		A /= 2;
		B += A;
		i++;
		if (i >= K) break;
		if (B % 2 == 1) B--;
		B /= 2;
		A += B;
	}
	cout << A << " " << B << endl;
}