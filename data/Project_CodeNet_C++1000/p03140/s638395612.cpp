#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, count = 0;
	string A, B, C;
	cin >> N >> A >> B >> C;
	for (int i = 0; i < N; i++) {
		if (A[i] == B[i] && B[i] == C[i]) count += 0;
		else if (A[i] == B[i] || B[i] == C[i] || C[i] == A[i]) count += 1;
		else count += 2;
	}
	cout << count;
}