#include <iostream>
#include <bitset>
using namespace std;

int N, A[100009], S;
bitset<4000009>I, J;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> A[i]; S += A[i]; }
	I.set(0);
	for (int i = 1; i <= N; i++) {
		J = (I << A[i]);
		I |= J;
	}
	for (int i = (S + 1) / 2; i <= S; i++) {
		if (I[i]) { cout << i << endl; break; }
	}
	return 0;
}