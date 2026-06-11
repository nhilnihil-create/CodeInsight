#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> B[i];
	long long Asum = 0, Bsum = 0, Alldif = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] >= B[i]) Bsum += (long long)A[i] - B[i];
		else Asum += (B[i] - A[i] + 1) / 2;
		Alldif += (long long)B[i] - A[i];
	}
	cout << (Alldif >= Asum && Alldif >= Bsum ? "Yes" : "No") << endl;
}
