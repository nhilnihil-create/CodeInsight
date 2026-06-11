#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <cmath>

using namespace std;

int main() {
	int N, ope;
	string A, B, C;
	cin >> N >> A >> B >> C;
	
	ope = 0;
	for (int i = 0; i < N; i++) {
		ope += max((A[i] != B[i]) + (B[i] != C[i]) + (C[i] != A[i]) - 1, 0);
	}
	
	cout << ope << endl;

	return 0;
}