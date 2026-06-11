#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	int64_t X, Y, Z, K;
	cin >> X >> Y >> Z >> K;

	vector<int64_t> A(X), B(Y), C(Z);
	for (int i = 0; i < X; i++) cin >> A[i];
	for (int i = 0; i < Y; i++) cin >> B[i];
	for (int i = 0; i < Z; i++) cin >> C[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());

	vector<int64_t> D;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j < Y; j++) {
			int64_t n = A[i] + B[j];
			D.push_back(n);
		}
	}
	sort(D.begin(), D.end());
	reverse(D.begin(), D.end());

	vector<int64_t> E;
	int64_t k = min(K, (int64_t)D.size());
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < Z; j++) {
			int64_t n = D[i] + C[j];
			E.push_back(n);
		}
	}
	sort(E.begin(), E.end());
	reverse(E.begin(), E.end());

	for (int i = 0; i < K; i++) {
		cout << E[i] << endl;
	}
}