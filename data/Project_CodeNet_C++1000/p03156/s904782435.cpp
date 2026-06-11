#include <iostream>
using namespace std;
int main(void) {
	int N, A, B, p;
	cin >> N >> A >> B;
	int cntA = 0, cntB = 0, cntC = 0;
	for (int i = 0; i < N; ++i) {
		cin >> p;
		if (p <= A) ++cntA;
		if (A < p && p <= B) ++cntB;
		if (B < p) ++cntC;
	}
	cout << min(cntA, min(cntB, cntC)) << endl;
	return 0;
}