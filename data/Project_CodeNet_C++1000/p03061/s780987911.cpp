#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int GCD(int a, int b) {
	if (!b) return a;
	else {
		return GCD(b, a % b);
	}
}

int main() {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	vector<int> A(N), B(N);
	for (int i = 1; i < N; i++) {
		A[i] = GCD(A[i - 1], v[i - 1]);
	}
	for (int i = N - 2; i >= 0; i--) {
		B[i] = GCD(B[i + 1], v[i + 1]);
	}

	vector<int> C(N);
	for (int i = 0; i < N; i++) {
		C[i] = GCD(A[i], B[i]);
	}
	sort(C.begin(), C.end());

	cout << C[N - 1] << endl;
}