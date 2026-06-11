#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	long long A, B, count = 0, MIN = 1145141919810364364;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		count += A;
		if (A > B) MIN = min(MIN, B);
	}
	cout << max((long long)0, count - MIN);
}