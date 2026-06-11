#include<iostream>
#include<algorithm>

using namespace std;

int Max(int x, int y) {
	for (int i = 1; i <= y; i++) {
		x = x * 2;
	}
	return x;
}

int main() {
	int A, B, C;
	int K;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> K;
	int M = max(A, max(B, C));
	cout << Max(M, K)+A+B+C-M;
}
